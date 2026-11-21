#include <stdlib.h>
#include <stdio.h>

#include <sys/types.h>

#include "fakeouts.h"

static void log_err(const char* funcname)
{
    fprintf(stderr, "ERROR unimplemented %s() call.\n", funcname);
    printf("ERROR unimplemented %s() call.\n", funcname);
}

void
warnc(int code, const char *fmt, ...)
{
    log_err(__func__);
}

char *
fgetln(FILE *fp, size_t *lenp)
{
    log_err(__func__);
    return NULL;
}


#ifdef USE_BUILTIN_ERRWARN
void
warn(int code, const char *fmt, ...)
{
    log_err(__func__);
}
void
warnx(int code, const char *fmt, ...)
{
    log_err(__func__);
}

void err(int eval, const char *fmt, ...)
{
    char *funcname = "err";

    fprintf(stderr, "ERROR unimplemented %s() call.\n", funcname);
    printf("ERROR unimplemented %s() call.\n", funcname);
}

void errx(int eval, const char *fmt, ...)
{
    char *funcname = "errx";

    fprintf(stderr, "ERROR unimplemented %s() call.\n", funcname);
    printf("ERROR unimplemented %s() call.\n", funcname);
    printf("eval = %d\n", eval);
    printf("fmt = >%s<\n", fmt);
}
#endif /* USE_BUILTIN_ERRWARN */

#ifdef USE_BUILTIN_PREAD
ssize_t pread(int fd, void *buf, size_t count, off_t offset)
{
    log_err(__func__);
    return 0;
}
#endif /* USE_BUILTIN_PREAD */
