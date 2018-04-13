#include "apue.h"
#include <sys/wait.h>

void pr_exit(int status)
{
    if (WIFEXITED(status))
        printf("normal termination, exit status = %d\n", WEXITSTATUS(status));
    else if (WIFSIGNALED(status))
        printf("abnormal termination, signal number = %d%s\n",
                WTERMSIG(status),
#ifdef  WCOREDUMP
                WCOREDUMP(status) ? " (core file genenrated)" : "");
#else
                "");
#endif
    else if (WIFSTOPPED(status))
        printf("child stoped, signal number = %d\n", WSTOPSIG(status));
}

int main2(void)
{
    pid_t   pid;
    int     status;
 
    if ((pid = fork()) < 0)
        err_sys("fork error");
    else if (pid == 0)      /* child */
        exit(7);

    if (wait(&status) != pid)   /* wati for child */
        err_sys("wait error");
    pr_exit(status);            /* and print its status */

    if ((pid = fork()) < 0)
        err_sys("fork error");
    else if (pid == 0)      /* child */
        abort();            /* generates SIGABRT */

    if (wait(&status) != pid)   /* wait for child */
        err_sys("wait error");
    pr_exit(status);            /* and print its status */

    if ((pid = fork()) < 0)
        err_sys("fork error");
    else if (pid == 0)          /* child */
        status /= 0;

    if (wait(&status) != pid)   /* wait for child */
        err_sys("wait error");
    pr_exit(status);            /* and print its status */

    exit(0);
}

