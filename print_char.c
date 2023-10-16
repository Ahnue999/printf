#include "main.h"

/**
 * print_char - Prints a char
 * @list: List a of arguments
 * @buffer: Buffer array
 * @flags:  flag characters
 * @width: field width
 * @precision: precision specifier
 * @size: size specifier
 */

int print_char(va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(list, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}
