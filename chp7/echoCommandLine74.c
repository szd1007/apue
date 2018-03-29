#include "apue.h"

int main(int argc, char *argv[])
{
    printf("NULL value string: %s\n", NULL);
    printf("NULL value int: %d\n", NULL);
    int i;
    for (i = 0; i < argc; i++)
    {
        printf("argv[%d]: %s\n", i, argv[i]);
    }
    exit(0);
}

