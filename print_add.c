#include "main.h"

/**
 * print_add - concatenates an address to the buffer.
 *
 * @argument: the integer to turn binary.
 * @buf: the buffer.
 * @pos: the position to add on.
 *
 * Return: the length of the address.
 */
int print_add(va_list argument, char *buf, unsigned int pos)
{
	int i, length, is_neg, first;
	long int n;
	char *bin, *hex;
	void *add;
	char *nil = "(nil)";

	add = (va_arg(argument, void *));
	if (add == NULL)
	{
		for (i = 0; nil[i]; i++)
			pos = input_buf(buf, nil[i], pos);
		return (i);
	}
	n = (unsigned long int)add;
	is_neg = 0;
	if (n < 0)
	{
		n = (n * -1) - 1;
		is_neg = 1;
	}
	bin = malloc(sizeof(char) * (64 + 1));
	bin = fill_bin(bin, n, is_neg, 64);
	hex = malloc(sizeof(char) * (16 + 1));
	hex = fill_hex(hex, bin, 0, 16);
	pos = input_buf(buf, '0', pos);
	pos = input_buf(buf, 'x', pos);
	for (first = i = length = 0; hex[i]; i++)
	{
		if (first == 0 && hex[i] != '0')
			first = 1;
		if (first)
		{
			pos = input_buf(buf, hex[i], pos);
			length++;
		}
	}
	free(bin), free(hex);
	return (length + 2);
}
