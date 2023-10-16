#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFSIZE 1024

typedef struct funcs
{
	char * ident;
	int (*func)(va_list, char *, unsigned int);
} funcs_t;

int _printf(const char *format, ...);
int input_buf(char *, char, unsigned int);
int print_buf(char *, int pos);
int (*get_func(const char *, int))(va_list, char *, unsigned int);
int print_char(va_list, char *, unsigned int);
int print_str(va_list, char *, unsigned int);
int print_dec(va_list, char *, unsigned int);

#endif
