#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFSIZE 1024

/**
  * funcs - a collection of identifiers with
  * their respective functions.
  *
  * @ident: an identifier name.
  * @func: a pointer to its function.
  *
  * Description: an identifiers structure
  */
typedef struct funcs
{
	char *ident;
	int (*func)(va_list, char *, unsigned int);
} funcs_t;

int _printf(const char *format, ...);
int input_buf(char *, char, unsigned int);
int print_buf(char *, unsigned int pos);
int (*get_func(const char *, int))(va_list, char *, unsigned int);
int print_chr(va_list, char *, unsigned int);
int print_str(va_list, char *, unsigned int);
int print_htr(va_list, char *, unsigned int);
int print_dec(va_list, char *, unsigned int);
int print_bin(va_list, char *, unsigned int);
int print_oct(va_list, char *, unsigned int);
int print_hex(va_list, char *, unsigned int);
int print_HEX(va_list, char *, unsigned int);
int print_add(va_list, char *, unsigned int);
int print_ui(va_list, char *, unsigned int);
char *fill_bin(char *, int, int, int);
char *fill_oct(char *oct, char *bin);
char *fill_hex(char *hex, char *bin, int, int);
int ev_print_func(const char *, int);

#endif
