#include "apue.h"
#include <fcntl.h>
#define RWRWRW (S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)
int main(int arg, char *argv[]){
    int fd = -1;
    unlink(argv[1]);
    if ((fd = creat(argv[1], RWRWRW)) < 0)
        err_sys("create %s error \n", argv[1]);
    printf("new fd %d", fd);
}

