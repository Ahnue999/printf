#include "main.h"

/**
 * print_dec - concatenate a decimal to the
 * buffer.
 *
 * @argument: the decimal.
 * @buf: the buffer.
 * @pos: the positiong to concatenate to.
 *
 * Return: The length of the decimal added.
 */
int print_dec(va_list argument, char *buf, unsigned int pos)
{
	int n, tmp, length = 0;
	int count, d, m;

	n = va_arg(argument, int);

	if (n < 0)
	{
		input_buf(buf, '-', pos), pos++;
		length++;
		m = n * -1;
	}
	else
		m = n;

	d = m;
	count = 1;
	while (d > 9)
	{
		d /= 10;
		count *= 10;
	}

	for (; count > 0; count /= 10)
	{
		tmp = ((m / count) % 10);
		input_buf(buf, tmp, pos), pos++;
		length++;
	}

	return (length);
}
