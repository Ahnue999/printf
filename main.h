#ifndef _MAIN_
#define _MAIN_

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFSIZE 1024

int _printf(const char *format, ...);
int input_buf(char *, char, unsigned int);
int print_buf(char *, int pos);

#endif
