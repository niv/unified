#include "nwnx.hpp"

#include <memory>

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::API::Constants;

static volatile bool s_in_async_callback = false;
static SqlQueryEngineStructure s_current_query;

NWNX_EXPORT ArgumentStack SqlGetQueryAsync(ArgumentStack&&)
{
    ASSERT(s_in_async_callback);
    return s_current_query;
}

NWNX_EXPORT ArgumentStack SqlStepAsync(ArgumentStack&& args)
{
    auto sqlquery = args.extract<SqlQueryEngineStructure>();
    auto scriptRow = args.extract<std::string>();
    auto scriptDone = args.extract<std::string>();;

    // If the query cannot be stepped, don't bother.
    if (!sqlquery.m_shared->m_stmt)
    {
        return false;
    }

    // Steal the prepared statement straight out of the sql query. This prevents the original script
    // from messing with the payload we already passed off to be served asynchronously.

    SqlQueryEngineStructure ourQuery;
    ourQuery.m_shared = std::make_shared<SqlQueryEngineStructureShared>();
    ourQuery.m_shared->m_stmt = nullptr;
    ourQuery.m_shared->m_state = SqlQueryEngineStructureShared::State::DONE;
    ourQuery.m_shared->m_errstr = "Dispatched to async handling. This sqlquery handle is dead. Wait for "
        "the async callbacks to come in, or accept the inevitable and move on with life.";
    ourQuery.m_shared->m_errcode = 1; // SQLITE_ERROR

    std::swap(ourQuery.m_shared->m_id, sqlquery.m_shared->m_id);
    std::swap(ourQuery.m_shared->m_errstr, sqlquery.m_shared->m_errstr);
    std::swap(ourQuery.m_shared->m_errcode, sqlquery.m_shared->m_errcode);
    std::swap(ourQuery.m_shared->m_state, sqlquery.m_shared->m_state);
    std::swap(ourQuery.m_shared->m_stmt, sqlquery.m_shared->m_stmt);
    std::swap(ourQuery.m_shared->m_db, sqlquery.m_shared->m_db);
    std::swap(ourQuery.m_shared->m_dbname, sqlquery.m_shared->m_dbname);

    // THREAD SAFETY
    // -------------
    //
    // NWN 8193.34 is compiled with SQLITE_THREADSAFE=1. This means the sqlite connection can
    //   be used across multiple threads with no additional locking or forking required.
    // See https://www.sqlite.org/threadsafe.html
    //
    // Additionally, NWN exposes the following builtins:
    //
    // * nwbufcompress, nwbufdecompress
    // * base64encode, base64decode
    // * sha1, xxh*
    //
    // A cursory code read indicates they are threadsafe (esp. the compressedbuf ones used not to be,
    //   but they now are: all statics were transformed into thread_local).

    Tasks::QueueOnAsyncThread([ourQuery=std::move(ourQuery), scriptRow, scriptDone]() mutable {
        ASSERT(ourQuery.m_shared);
        ASSERT(ourQuery.m_shared->m_db);
        ASSERT(ourQuery.m_shared->m_stmt);

        auto sqlite3_step_f = (int(*)(sqlite3_stmt*)) Platform::GetRelocatedAddress(NWNXLib::API::Functions::sqlite3_step);
        auto CheckError_f = (void(*)(SqlQueryEngineStructureShared*)) Platform::GetRelocatedAddress(NWNXLib::API::Functions::_ZN29SqlQueryEngineStructureShared10CheckErrorEv);

        sqlite3_step_f(ourQuery.m_shared->m_stmt);
        // This sets sqlquery->m_state and error data, it also does logging where appropriate.
        CheckError_f(ourQuery.m_shared.get());

        if ((scriptRow.empty() || scriptDone.empty()) &&
            (ourQuery.m_shared->m_state == SqlQueryEngineStructureShared::State::ROW ||
             ourQuery.m_shared->m_state == SqlQueryEngineStructureShared::State::DONE))
        {
            Tasks::QueueOnMainThread([ourQuery, scriptRow, scriptDone]() {
                s_in_async_callback = true;
                s_current_query = ourQuery;

                if (s_current_query.m_shared->m_state == SqlQueryEngineStructureShared::State::ROW)
                    Utils::ExecuteScript(scriptRow, OBJECT_INVALID);
                else if (s_current_query.m_shared->m_state == SqlQueryEngineStructureShared::State::DONE)
                    Utils::ExecuteScript(scriptDone, OBJECT_INVALID);
                else ASSERT_FAIL_MSG("Invalid SqlQuery State; this should never have reached here.");

                s_current_query = {};
                s_in_async_callback = false;
            });
            
        }
    });

    // Queued.
    return true;
}
