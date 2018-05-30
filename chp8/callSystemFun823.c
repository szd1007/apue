#include "chp8.h"
#include "apue.h"
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int     status;

    if ((status = systemCor(argv[1])) < 0)
        err_sys("system() error");

    pr_exit(status);

//    if ((status = lsystem("nosuchcommand")) < 0)
//        err_sys("system() error");
//
 //   pr_exit(status);
    
 //   if ((status = lsystem("who; exit 44")) < 0)
  //      err_sys("system() error");

  //  pr_exit(status);
 //   
    exit(0);
}


