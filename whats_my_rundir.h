#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#ifdef APPLE
#   include <string.h>
#   include <errno.h>
#   include <libproc.h>
#else
#   include <sys/types.h>
#   include <sys/stat.h>
#   include <limits.h>
#endif

