#include "apue.h"
#include <pwd.h>

static void my_alarm(int signo)
{
    struct passwd   *rootptr;

    printf("in signal handler\n");
    if ((rootptr = getpwnam("root")) == NULL)
       err_sys("getpwnam(root) error");
   // printf("before alarm ,name;%s\n", rootptr->pw_name);
    alarm(1);
    printf("exit signal handler\n");
}

int main(void)
{
    struct passwd   *ptr;

    signal(SIGALRM, my_alarm);
    alarm(1);
    for( ; ; ) {
        if ((ptr = getpwnam("zm")) == NULL)
            err_sys("getpwnam error");
        if (strcmp(ptr->pw_name, "zm") != 0)
            printf("return valued corrupted!, pw_name = %s\n", ptr->pw_name);
//        printf("in loop %s\n", ptr->pw_name);
    }
}

