@page sqlext Readme
@ingroup sqlext

Provides various extensions to the SQL functionality already built into the game.

## Async

Allows you to step and run queries asynchronously (on a background thread). You can optionally be
called back on ROW data.
### run.nss

```c
#include "nwnx_sqlext"

void main()
{
  WriteTimestampedLogEntry("MOD_LOAD");

  // Set up test table.
  SqlStep(SqlPrepareQueryObject(GetModule(), "create table test (value text);"));
  SqlStep(SqlPrepareQueryObject(GetModule(), "insert into test (value) values ('hi'), ('there'), ('nwnx');"));

  sqlquery q = SqlPrepareQueryObject(GetModule(), "select * from test;");

  int ret = NWNX_SqlExt_SqlStepAsync(q, "row", "done");
  WriteTimestampedLogEntry("Dispatched query async; query state now: " + SqlGetError(q));
}
```
### row.nss

```c
#include "nwnx_sqlext"

void handleRow(sqlquery handle)
{
  string ret = SqlGetString(handle, 0);
  WriteTimestampedLogEntry("RET (async) = '" + ret + "'");
}

void main()
{
  WriteTimestampedLogEntry("Enter `test`");

  sqlquery handle = NWNX_SqlExt_SqlGetQueryAsync();

  // this is inside sqlstep(); we are already true-ish on the given handle.
  handleRow(handle);

  // Eat all remaining rows too, while we're here.
  while (SqlStep(handle)) handleRow(handle);
}
```

### done.nss

```c
#include "nwnx_sqlext"

void main()
{
  WriteTimestampedLogEntry("Enter `done`");

  sqlquery handle = NWNX_SqlExt_SqlGetQueryAsync();
  string result = SqlGetError(handle);

  WriteTimestampedLogEntry("Result: " + result);
}
```
