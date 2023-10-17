#include "main.h"

/**
 * print_oct - concatenates an octal to the buffer.
 *
 * @argument: the integer to turn octal.
 * @buf: the buffer.
 * @pos: the position to add on.
 *
 * Return: the length of the octal.
 */
int print_oct(va_list argument, char *buf, unsigned int pos)
{
	int n, i, length, first, is_neg = 0;
	char *bin, *oct;

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
	bin = fill_bin(bin, n, is_neg, 32);
	oct = malloc(sizeof(char) * (11 + 1));
	oct = fill_oct(oct, bin);

	for (first = i = 0; oct[i]; i++)
	{
		if (oct[i] != '0' && first == 0)
			first = 1;
		if (first == 1)
		{
			pos = input_buf(buf, oct[i], pos);
			length++;
		}

	}
	free(bin);
	free(oct);
	return (length);
}

/**
 * print_soct - concatenates a short octal to the buffer.
 *
 * @argument: the integer to turn octal.
 * @buf: the buffer.
 * @pos: the position to add on.
 *
 * Return: the length of the octal.
 */
int print_soct(va_list argument, char *buf, unsigned int pos)
{
	short n, i, length, first, is_neg = 0;
	char *bin, *oct;

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

	bin = malloc(sizeof(char) * (16 + 1));
	bin = fill_bin(bin, n, is_neg, 16);
	oct = malloc(sizeof(char) * (6 + 1));
	oct = fill_oct(oct, bin);

	for (first = i = 0; oct[i]; i++)
	{
		if (oct[i] != '0' && first == 0)
			first = 1;
		if (first == 1)
		{
			pos = input_buf(buf, oct[i], pos);
			length++;
		}

	}
	free(bin);
	free(oct);
	return (length);
}

/**
 * print_loct - concatenates an octal to the buffer.
 *
 * @argument: the integer to turn octal.
 * @buf: the buffer.
 * @pos: the position to add on.
 *
 * Return: the length of the octal.
 */
int print_loct(va_list argument, char *buf, unsigned int pos)
{
	long int n, i, length, first, is_neg = 0;
	char *bin, *oct;

	n = va_arg(argument, long int);

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

	bin = malloc(sizeof(char) * (64 + 1));
	bin = fill_bin(bin, n, is_neg, 64);
	oct = malloc(sizeof(char) * (22 + 1));
	oct = fill_oct(oct, bin);

	for (first = i = 0; oct[i]; i++)
	{
		if (oct[i] != '0' && first == 0)
			first = 1;
		if (first == 1)
		{
			pos = input_buf(buf, oct[i], pos);
			length++;
		}

	}
	free(bin);
	free(oct);
	return (length);
}
