#include "apue.h"

int globvar = 6;    /* external variable in initialized data */

int main(void)
{
    int     var;    /* automatic variable on the stack */
    pid_t   pid;

    var = 88;
    printf("before vfork\n");   /* we don't flush stdio */
    if ((pid = vfork()) < 0) {
        err_sys("vfork error");
    } else if (pid == 0) {      /* child */
        globvar++;              /* modify parent's variables */
        var++;
        //exit(0);               /* child terminates exit会执行额外的清理操作，win下会影响父进程的File Io 导致 父进程printf失败*/
        _exit(0);               /* child terminates */
    }

    /* parent continues here */
    printf("pid = %ld, glob = %d, var= %d\n", (long)getpid(), globvar, var);
    exit(0);
}

