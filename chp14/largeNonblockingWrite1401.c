#include "apue.h"
#include <errno.h>
#include <fcntl.h>

char    buf[500000];
void set_fl(int fd, int fileStatusFlag)
{
    int flag = fcntl(fd, F_GETFL);
    flag |= O_NONBLOCK;
    if (fcntl(fd, F_SETFL, flag) == -1)
    {
        err_sys("fcntl error");
    }
}
void clr_fl(int fd, int fileStatusFlag)
{
    int flag = fcntl(fd, F_GETFL);
    flag &= !O_NONBLOCK;
    if (fcntl(fd, F_SETFL, flag) == -1)
    {
        err_sys("fcntl error");
    }
}



int main(void)
{
    int         ntowrite, nwrite;
    char        *ptr;

    ntowrite = read(STDIN_FILENO, buf, sizeof(buf));;
    fprintf(stderr, "read %d bytes\n", ntowrite);

    set_fl(STDOUT_FILENO, O_NONBLOCK);  /* set nonblocking */

    ptr = buf;
    while (ntowrite > 0) {
        errno = 0;
        nwrite = write(STDOUT_FILENO, ptr, ntowrite);
        fprintf(stderr, "nwrite = %d, errno = %d\n", nwrite, errno);

        if (nwrite > 0) {
            ptr += nwrite;
            ntowrite -= nwrite;
        }
    }
    
    clr_fl(STDOUT_FILENO, O_NONBLOCK); /* clear nonblocking */

    exit(0);
}


