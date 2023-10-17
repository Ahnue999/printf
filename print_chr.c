#include "main.h"

/**
 * print_chr - concatenates the provided char
 * to the buffer.
 *
 * @list: contains the char to add.
 * @buf: the buffer.
 * @pos: the position to concatenate to.
 *
 * Return: 1 (the size of a char).
 */
int print_chr(va_list list, char *buf, unsigned int pos)
{
	char c;

	c = va_arg(list, int);
	input_buf(buf, c, pos);

	return (1);
}

/**
 * print_per - concatenate % to the buffer.
 * @a: input char.
 * @buf: the buffer.
 * @pos: position to add on.
 * Return: On success 1.
 */
int print_per(va_list a __attribute__((unused)), char *buf, unsigned int pos)
{
	input_buf(buf, '%', pos);

	return (1);
}
