#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    time_t t;
    struct tm *tmp;
    char buf2[64];

    time(&t);
    tmp = localtime(&t);
    if (strftime(buf2, 64, "%G年 %m %d日 %A %H时%M分%S秒 %Z", tmp) == 0)
        printf("buffer length 64 is to small\n");
    else
        printf("%s\n", buf2);
    exit(0);
}
