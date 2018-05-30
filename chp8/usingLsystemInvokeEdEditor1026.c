#include "apue.h"
#include "chp8.h"

static void sig_int(int signo)
{
    printf("caught SIGINT\n");
}

static void sig_chld(int signo)
{
    printf("caught SIGCHLD\n");
}

int main(void)
{
    if (signal(SIGINT, sig_int) == SIG_ERR)
        err_sys("signal(SIGINT) error");
    if (signal(SIGCHLD, sig_chld) == SIG_ERR)
        err_sys("signal(SIGCHLD) error");
    //if (lsystem("/bin/ed") < 0)
    if (systemCor("/bin/ed") < 0)
        err_sys("system() error");
    exit(0);
}

