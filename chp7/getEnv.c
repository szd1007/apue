#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    printf("COLUMNS %s\n", getenv("COLUMNS"));
    printf("PATH %s\n", getenv("PATH"));
    printf("LC_COLLATE %s\n", getenv("LC_COLLATE"));
    return(0);
}

