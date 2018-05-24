#include "apue.h"
static void sig_int(int sig)
{
    printf("in sig_int");
}
static void sig_usr(int sig)
{
    printf("in sig_usr");
}


int main(void)
{
    sigset_t newmask, oldmask, waitmask;

    if (signal(SIGINT, sig_int) == SIG_ERR)
        err_sys("errr");
    signal(SIGUSR1, sig_usr);
    sigemptyset(&waitmask);
    sigaddset(&waitmask, SIGUSR1);
    sigemptyset(&newmask);
    sigaddset(&newmask, SIGINT);

    sigprocmask(SIG_BLOCK, &newmask, &oldmask);
    
    sigsuspend(&waitmask);//除了waitmask掩码之外的信号唤醒

    printf("wake up");
    exit(0);
}
