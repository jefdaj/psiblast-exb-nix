#! /bin/sh

# DBLIB does not work (on Linux at least) when this limit is > 1024
ulimit -n 1536 > /dev/null 2>&1

syb="No_Sybase"
if test -d "$syb" -o -z "$SYBASE"; then
    SYBASE=$syb
    export SYBASE
fi

if [ ".$1" = ".-run-script" ]; then
   shift
   exec "$@"
fi
exec $CHECK_EXEC "$@"
