#include "chp8.h"
#include "apue.h"
#include <sys/wait.h>

int main(void)
{
    int     status;

    if ((status = lsystem("date")) < 0)
        err_sys("system() error");

    pr_exit(status);

    if ((status = lsystem("nosuchcommand")) < 0)
        err_sys("system() error");

    pr_exit(status);
    
    if ((status = lsystem("who; exit 44")) < 0)
        err_sys("system() error");

    pr_exit(status);
    
    exit(0);
}


