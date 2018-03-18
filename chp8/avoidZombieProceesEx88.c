#include "apue.h"
#include <sys/wait.h>

int main(void)
{
    pid_t   pid;

    if ((pid = fork()) < 0) {
        err_sys("fork error");
    } else if (pid == 0) {  /* first child */
        printf("first child, parent pid = %ld\n", (long)getppid());
        if ((pid = fork()) < 0)
            err_sys("fork error");
        else if(pid > 0)
            exit(0);    /* parent of the second fork == first child */
        /*
         * We're the second child; out parent becomes init as soon as our real
         * parent calls exit() in the statement above. Here's where we'd conti
         * nue executing, konwing that when we're done, init will reap our status.
         */

        sleep(2);
        printf("second child, parent pid = %ld\n", (long)getppid());
        exit(0);
    }

    printf("parent pid %ld, first child pid %ld\n", (long)getpid(), (long)pid);

    if (waitpid(pid, NULL, 0) != pid)   /* wait for first child */
        err_sys("waitpid error");

    /*
     * We're the parent (the original process); we continue executing,
     * knowing that we're not the parent of the second child.
     */
    exit(0);
}

