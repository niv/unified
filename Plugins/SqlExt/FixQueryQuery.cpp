#include "nwnx.hpp"
#include "API/CVirtualMachine.hpp"
#include "API/CVirtualMachineStack.hpp"
#include "API/StackElement.hpp"

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::API::Constants;

static Hooks::Hook s_VMCommandSqlPrepare_Hook;

// SqlQuery type is not correctly setting the m_query field. We'd like to use it internally,
// so we patch it after ctoring.

static void FixQueryQuery() __attribute__((constructor));
static void FixQueryQuery()
{
    s_VMCommandSqlPrepare_Hook = Hooks::HookFunction(
        API::Functions::_ZN25CNWVirtualMachineCommands24ExecuteCommandSqlPrepareEii,
        (void*) +[](CNWVirtualMachineCommands* thisPtr, int32_t a, int32_t b) -> int32_t {

            auto* vmstack = &API::Globals::VirtualMachine()->m_cRunTimeStack;

            // The original query should live at Top-1 for all Prepare() calls (first func arg).
            ASSERT(vmstack->m_nStackPointer > 1);
            ASSERT(vmstack->m_pchStackTypes[vmstack->m_nStackPointer - 2] == 5); // STRING
            CExoString orgQuery = *(CExoString*)vmstack->m_pStackNodes[vmstack->m_nStackPointer - 2].m_pStackPtr;

            int32_t ret = s_VMCommandSqlPrepare_Hook->CallOriginal<int32_t>(thisPtr, a, b);

            if (ret == VMError::Success)
            {
                // sqlquery retval is top of stack.
                ASSERT(vmstack->m_nStackPointer > 0);
                ASSERT(vmstack->m_pchStackTypes[vmstack->m_nStackPointer - 1] == 21); // AUX ENGST5
                auto* ptr = (SqlQueryEngineStructure*) vmstack->m_pStackNodes[vmstack->m_nStackPointer - 1].m_pStackPtr;
                ASSERT(ptr->m_shared);
                ASSERT(ptr->m_shared->m_query.IsEmpty());

                ptr->m_shared->m_query = orgQuery;

                ASSERT(ptr);
            }
           
            return ret;
        },
        Hooks::Order::Late);
}
