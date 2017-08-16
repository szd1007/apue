#include "apue.h"
#include <errno.h>
///usr/include/asm-generic/errno-base.h
int main(int argc, char  *argv[])
{
    fprintf(stderr, "EACESS: %s\n", strerror(EACCES));
    errno = EIO;
    perror(argv[0]);
    exit(0);
}
