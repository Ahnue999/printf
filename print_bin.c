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
	int n, i, length, first, is_neg = 0;
	char *bin;

	n = va_arg(argument, int);

	if (n == 0)
	{
		input_buf(buf, '0', pos);
		return (1);
	}

	if (n < 0)
	{
		n = (n * -1) - 1;
		is_neg = 1;
	}

	bin = malloc(sizeof(char) * (32 + 1));
	bin = fill_bin(bin, n , is_neg, 32);

	first = 0;
	for (i = length = 0; bin[i]; i++)
	{
		if (first == 0 && bin[i] == '1')
			first = 1;
		if (first == 1)
		{
			pos = input_buf(buf, bin[i], pos);
			length++;
		}

	}
	free(bin);
	return (length);
}
