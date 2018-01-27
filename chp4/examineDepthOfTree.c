#include "apue.h"

#define RXRXRX (S_IRUSR|S_IXUSR|S_IWUSR|S_IRGRP|S_IXGRP|S_IROTH|S_IXOTH)
#define loops 1000
static const char * folder_name = "tt" ;
int main(void)
{
    for ( int i = 0; i < loops; i++){
        if (mkdir(folder_name, RXRXRX) < 0)
            err_sys("mkdir error");
        if (chdir(folder_name) < 0){
            err_sys("chdir %sfailed\n", folder_name);
        }
        else{ printf("chdir %s succes %d\n", folder_name, i);}

    }
}


