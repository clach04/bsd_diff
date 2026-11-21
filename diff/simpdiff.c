#include <sys/stat.h>
#include <sys/stat.h>

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

#include "diff.h"
#include "xmalloc.h"


int	 sflag=0;
int	 diff_format=0, diff_context=0, status=0;
char	*diffargs=NULL, *ifdefname=NULL, *label[2], *ignore_pats=NULL;
struct stat stb1, stb2;
int	 Tflag=0;
#ifndef DISABLE_REGEX
regex_t	 ignore_re;
#endif /* DISABLE_REGEX */

int
diff_two_files_to_stdout(char* filename_orig, char* filename_new)
{
    int   dflags=0;

    label[0] = NULL;
    label[1] = NULL;

    diff_format = D_NORMAL;
    /*
    diff_format = D_UNIFIED;
    */
    diff_context = 0;
    status = 0;
    print_status(diffreg(filename_orig, filename_new, dflags), filename_orig, filename_new, "");

    return status;
}

void
print_status(int val, char *path1, char *path2, char *entry)
{
    switch (val) {
    case D_BINARY:
        printf("Binary files %s%s and %s%s differ\n",
            path1, entry, path2, entry);
        break;
    }
}

