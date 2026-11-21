# Hacked up BSD diff

This only contains the code for diff, from OpenBSD (circa 2014),
with some porting changes so it builds and runs on non-BSD platforms
(Linux, Windows, and VMS tested so far). The internal diff function
has code for warning "don't diff binary files".

I've a vague recollection building under Mac OSX required NOT building with strlcat.c and strlcpy.c

Predates diff dir support. Probably won't build on OpenBSD

## build

```bash
cd diff
gcc -o diff.exe -I. -DDISABLE_REGEX -DDISABLE_PR_PRINT -DDISABLE_TEMP -DDISABLE_NULLDEVICE -DUSE_BUILTIN_ERRWARN -DUSE_BUILTIN_PREAD  diff.c diffreg.c xmalloc.c   fakeouts.c strlcat.c strlcpy.c```

## changes

features

  * Environmental variable look up for `TMPDIR`
  * Use as a library
  * Build under Linux with gcc
  * Build under Microsoft Windows with gcc
  * Build under Microsoft Windows with msvcc

Code

  * simplediff.c
  * fakeouts.h / fakeouts.c
  * `str*.c` implementations for platforms that need them
  * pathnames.h - from OpenBSD
  * a bunch of `DISABLE_` macros
      * `DISABLE_REGEX`
      * `DISABLE_PR_PRINT`
      * `DISABLE_TEMP`
      * `DISABLE_NULLDEVICE`
      * `DISABLE_XASPRINTF`
  * a bunch of `USE_BUILTIN_` macros
      * `USE_BUILTIN_PREAD`
      * `USE_BUILTIN_ERRWARN`

## diff resources

  * https://github.com/openbsd/src/tree/master/usr.bin/diff
      * https://github.com/openbsd/src/commits/master/usr.bin/diff/diff.c
  * https://cgit.freebsd.org/src/tree/usr.bin/diff
      * https://cgit.freebsd.org/src/log/usr.bin/diff/diff.c
  * https://github.com/chimera-linux/bsddiff
