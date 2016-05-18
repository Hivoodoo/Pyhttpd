# Pyhttpd
A project for practice. Implement a web server which can use python in web

## Log
this class implement to output log

### Point
`time.h`(or `ctime`) is a stdard header, which function time is define in. the `time_t time(time_t *t)` returns the time as the number of seconds since the Epoch, 1970-01-01 00:00:00 +0000 (UTC).
If t is non-NULL, the return value is also stored in the memory pointed to by t.
As above, the minimum unit is second.

the `int gettimeofday(struct timeval *tv, struct timezone *tz);` is accurate. you can use `struct timeval` to get seconds and micoroseconds of a day.
this function is include in `sys/time.h` which can only use in Unix-like system.

## ServerException
use to been raise. Should call with Error Code.
0. Connector create ERROR
1. openListen ERROR
2. work ERROR
3. send ERROR
4. MQ ERROR
