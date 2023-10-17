#include "main.h"

/**
 * print_ui - concatenate an unsigned integer
 * to the buffer.
 *
 * @argument: the unsigned integer.
 * @buf: the buffer.
 * @pos: the positiong to concatenate to.
 *
 * Return: The length of the decimal added.
 */
int print_ui(va_list argument, char *buf, unsigned int pos)
{
	unsigned int n, tmp, length = 0;
	unsigned int count, d;

	n = va_arg(argument, unsigned int);
	
	d = n;
	count = 1;
	while (d > 9)
	{
		d /= 10;
		count *= 10;
	}

	for (length = 0; count > 0; count /= 10, length++)
	{
		tmp = ((n / count) % 10);
		input_buf(buf, ('0' + tmp), pos), pos++;
	}

	return (length);
}
