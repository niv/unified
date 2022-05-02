#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"

#include <memory>

struct sqlite3;
struct sqlite3_stmt;

#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(SqlQueryEngineStructure)
#endif

namespace sqlite {
class database {
	// protected:
public:
    std::shared_ptr<sqlite3> _db;
};
}

struct SqlQueryEngineStructureShared
{
    uint64_t m_id;

    // We keep a handle to the database so it doesn't close on us while
    // the query is still running.
    CExoString m_dbname;
    CExoString m_query;
    std::shared_ptr<sqlite::database> m_db;

    // The compiled statement. null if not initialised or errored out.
    sqlite3_stmt* m_stmt = nullptr;

    // The last-seen/checked error data.
    int m_errcode = 0;
    CExoString m_errstr;

    enum class State { EMPTY, NEW, ROW, DONE };
    State m_state = State::EMPTY;
};

struct SqlQueryEngineStructure : public SharedPtrEngineStructure<SqlQueryEngineStructureShared>
{
    virtual ~SqlQueryEngineStructure() {}

#ifdef NWN_CLASS_EXTENSION_SqlQueryEngineStructure
    NWN_CLASS_EXTENSION_SqlQueryEngineStructure
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(SqlQueryEngineStructure)
#endif
