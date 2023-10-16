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

	n = va_arg(argument, int);

	if (n > 0)
	{
		while(i--)
		{
			if (n % 2 == 0)
			{
				get_bin(n / 2);
				input_buf(buf, '0', pos);
				pos++;
			}
			else
			{
				get_bin((n - 1) / 2);
				input_buf(buf, '0', pos);
				pos++;
			}
		}
	}

	return (8);
}
