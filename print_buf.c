#include "main.h"

/**
 * print_buf - prints the current buffer.
 *
 * @c: the buffer.
 * @pos: characters in the buffer.
 * Return: 1 when success otherwhise 0
 */
int print_buf(char *c, unsigned int pos)
{
	return (write(1, c, pos));
}
