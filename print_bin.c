#include "main.h"

/**
 * print_bin - concatenates a binary to the buffer.
 *
 * @argument: the integer to turn binary.
 * @buf: the buffer.
 * @pos: the position to add on.
 *
 * Return: the length of the bin (8).
 */
int print_bin(va_list argument, char *buf, unsigned int pos)
{
	int i = 8, n;
	int bin[8];

	n = va_arg(argument, int);

	if (n > 0)
	{
		for (i = 7; i >= 0; i--, n /= 2)
		{
			if (n % 2 == 0)
				bin[i] = 0;
			else
				bin[i] = 1;
		}
	}

	for (i = 0; i < 8; i++, pos++)
	{
		input_buf(buf, ('0' + bin[i]), pos);
	}

	return (8);
}
