# Hacked up BSD diff

This only contains the code for diff, from OpenBSD (circa 2014),
with some porting changes so it builds and runs on non-BSD platforms
(Linux, Windows, and VMS tested so far). The internal diff function
has code for warning "don't diff binary files".

I've a vague recollection building under Mac OSX required NOT building with strlcat.c and strlcpy.c

## diff resources

  * https://github.com/openbsd/src/tree/master/usr.bin/diff
      * https://github.com/openbsd/src/commits/master/usr.bin/diff/diff.c
  * https://cgit.freebsd.org/src/tree/usr.bin/diff
      * https://cgit.freebsd.org/src/log/usr.bin/diff/diff.c
  * https://github.com/chimera-linux/bsddiff
