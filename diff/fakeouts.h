#ifndef _FAKEOUTS_H
#define _FAKEOUTS_H

/*
BSD typedefs
*/

#ifndef __u_char_defined
/*
** NOTE some/most? platforms that implement u_ABC types in sys/types
** also define macros to allow detection, viz. __u_char_defined
*/
typedef unsigned char   u_char;
typedef unsigned int    u_int;
typedef unsigned long   u_long;
#endif /* __u_char_defined */

#ifndef MAX
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#endif

#ifndef MIN
#define MIN(x, y) (((x) < (y)) ? (x) : (y))
#endif

#if defined(_MSC_VER)
    /*
    ** MSVC compilers do not implement __func__ :-(
    ** BUT MSVC v7 have __FUNCTION__
    */
    #if _MSC_VER < 1300
        #define __func__ "unknown function"
    #else
        #define __func__ __FUNCTION__
    #endif /* _MSC_VER < 1300 */

    #define ssize_t size_t  /* ughhh */

    #ifndef S_ISDIR
    #define S_ISDIR(mode)  (((mode) & S_IFMT) == S_IFDIR)
    #endif
#endif /* defined(_MSC_VER) */

/* not sure what this is, so just "remove" it */
#define __dead

#endif /* _FAKEOUTS_H */
