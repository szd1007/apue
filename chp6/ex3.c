#include "apue.h"
#include <sys/utsname.h>

int main(void)
{
    struct utsname *ume;

    if (uname(ume) == -1)
    {
        err_sys("get uname error");
    }
    
    printf("sysname %s\n", ume->sysname);
    printf("nodename %s\n", ume->nodename);
    printf("release %s\n", ume->version);
    printf("machine %s\n", ume->machine);

    return 0;
}
