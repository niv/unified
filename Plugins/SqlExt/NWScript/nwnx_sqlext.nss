/// @addtogroup sql SqlExt
/// @brief Expands builtin sql support
/// @{
/// @file nwnx_sqlext.nss
#include "nwnx"

const string NWNX_SqlExt = "NWNX_SqlExt"; ///< @private

/// @brief Steps the given query on a background thread, and calls you back on `script` when
//         the step returns. The returning script can fetch the query with
//         NWNX_SqlExt_SqlGetQueryAsync(); you can keep stepping async or start stepping sync.
/// @note It is VERY IMPORTANT that you do not step the query after you have passed it to Async,
///       and Async said TRUE.
/// @param query A prepared query.
/// @param scriptRow A script callback to invoke when ROW data is available (for each row).
/// @param scriptDone A script callback to invoke when no more rows are available (or a error happened).
///        Errors always go to the server log, in addition to any script provided here.
/// @return TRUE if the query was dispatched to background.
int NWNX_SqlExt_SqlStepAsync(sqlquery query, string scriptRow, string scriptDone = "");

/// @brief Retrieve the sqlquery instance which has row data available.
/// @note Only valid from within a StepAsync callback script.
sqlquery NWNX_SqlExt_SqlGetQueryAsync();

/// @}

int NWNX_SqlExt_SqlStepAsync(sqlquery query, string scriptRow, string scriptDone = "")
{
    string sFunc = "SqlStepAsync";
    NWNX_PushArgumentString(scriptDone);
    NWNX_PushArgumentString(scriptRow);
    NWNX_PushArgumentSqlQuery(query);
    NWNX_CallFunction(NWNX_SqlExt, sFunc);
    return NWNX_GetReturnValueInt();
}

sqlquery NWNX_SqlExt_SqlGetQueryAsync()
{
    string sFunc = "SqlGetQueryAsync";
    NWNX_CallFunction(NWNX_SqlExt, sFunc);
    return NWNX_GetReturnValueSqlQuery();
}
