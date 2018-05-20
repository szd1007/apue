#include <setjmp.h>
#include <signal.h> 
#include <unistd.h>
#include <stdio.h>

static jmp_buf env_alrm;

static void sig_alrm(int signo)
{
    longjmp(env_alrm, 1);
}

unsigned int sleep22(unsigned int seconds)
{
    if (signal(SIGALRM, sig_alrm) == SIG_ERR)
        return(seconds);
    if (setjmp(env_alrm) == 0) {
        printf("before alarm \n");
        alarm(seconds);     /* start the timer */
        printf("after alarm \n");
        pause();            /* next caught signal wakes us up */
        printf("after pause \n");
    }
    return(alarm(0));       /* turn off timer, return unslept time */
}

int main2(void)
{
    sleep22(2);
}
