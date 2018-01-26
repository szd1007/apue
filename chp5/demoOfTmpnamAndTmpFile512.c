/*************************************************************************
	> File Name: demoOfTmpnamAndTmpFile512.c
	> Author: adamx
	> Mail: szd1007@163.com 
	> Created Time: Fri 26 Jan 2018 01:20:39 PM CST
 ************************************************************************/

#include "apue.h"

int main(void)
{
	char	name[L_tmpnam], line[MAXLINE];
	FILE	*fp;

	printf("%s\n", tmpnam(NULL));

	
