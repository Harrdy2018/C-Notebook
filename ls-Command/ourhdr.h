/*Our own header, to be included *after* all standard system headers*/
#ifndef __ourhdr_h
#define __ourhdr_h

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAXLINE 4096  /*max line length*/
#endif

void err_quit(const char *,...);
void err_sys(const char *,...);
