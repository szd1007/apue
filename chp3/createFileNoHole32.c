#include "apue.h"
#include <fcntl.h>

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int main(void)
{
    int fd;
    char * buf = malloc(16394);
    memset(buf, 't', 16394);
    if ((fd = creat( "file.noHole", FILE_MODE)) <0)
        err_sys("CREAT error");
    if (write(fd, buf, 16394) !=16394)
        err_sys("buf1 write error");
    /*offset now = 16394 */
    exit(0);
}


