#include "apue.h"
#include <setjmp.h>

#define TOK_ADD 5

jmp_buf jmpbuffer;

void    do_line(char *);
void    cmd_add(void);
int     get_token(void);

int main(void)
{
    char    line[MAXLINE];
    int jmpRet = setjmp(jmpbuffer);
    if (jmpRet != 0)
        printf("error, setjmp return %d\n", jmpRet);
    while (fgets(line, MAXLINE, stdin) != NULL)
        do_line(line);
    exit(0);
}

void cmd_add(void)
{
    int     token;

    token = get_token();
    if(token == 5)
        token = -1;
    if (token < 0)  /* an error has occured */
        longjmp(jmpbuffer, 1);
    /* rest of processing for this command */
}

char    *tok_ptr;   /* global pointer for get_token() */

void do_line(char *ptr)
{
    int     cmd;
    tok_ptr = ptr;
    while ((cmd = get_token()) > 0)
    {
        switch  (cmd) {
            case TOK_ADD:
                cmd_add();
                break;
        }
        break;
    }
}

int get_token(void)
{
    /* fetch next token from line pointed to by tok_ptr */
    printf("get input %s\n", tok_ptr);
    int token = tok_ptr[0] - '0';
    printf("get token %d\n", token);
    return token;
}

