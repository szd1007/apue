#include "apue.h"
#include <fcntl.h>
#include <sys/mman.h>

#define MAP_ANON 0x1000
#define NLOOPS  10
#define SIZE    sizeof(long)    /* size of shared memory */

static int update(long *ptr)
{
    return ((*ptr)++);   /* return value before inrement */
}

int main(void)
{
    int     fd, i, counter;
    pid_t   pid;
    void    *area;

    if ((area = mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_ANON | MAP_SHARED, -1, 0)) == MAP_FAILED){
        err_sys("mmap error");
    } 
    TELL_WAIT();
    if ((pid = fork()) < 0) {
        err_sys("fork error");
    } else if (pid > 0) {   /* parent */
        printf("parent\n");
        for (i = 0; i< NLOOPS; i += 2) {
            printf("parent begin\n ");
            if ((counter = update((long *)area)) != i)
                err_quit("parent: expected %d, got %d", i, counter);
            printf("parent end \n");
            TELL_CHILD(pid);
            WAIT_CHILD();
        }
    } else {    /* child */
        printf("child\n");
        //sleep(3);
        for (i = 1; i < NLOOPS +1; i += 2) {
            WAIT_PARENT();

            printf("child begin %ld\n ", *(long *)area);
            if ((counter = update((long *) area)) != i)
                err_quit("child: expected %d, got %d", i, counter);
            printf("child end \n");
            TELL_PARENT(getppid());
        }
    }
    exit(0);
}


