#include "apue.h"
#include <pwd.h>

int main(void)
{
    struct passwd * pwd;
    if( (pwd = getpwnam("zm")) == NULL)
    {
        printf("get pwname error");
        return -1;
    } else {
        printf("name %s , encrypted password %s", pwd->pw_name, pwd->pw_passwd);
    }
    return 0;
}


