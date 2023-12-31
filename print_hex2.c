#include "main.h"

/**
 * print_NHEX - concatenates an upper hexadecimal to the buffer.
 *
 * @argument: the integer to turn hexadecimal.
 * @buf: the buffer.
 * @pos: the position to add on.
 *
 * Return: the length of the octal
 */
int print_NHEX(va_list argument, char *buf, unsigned int pos)
{
	int n, i, length, first, is_neg = 0;
	char *bin, *hex;

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

	pos = input_buf(buf, '0', pos);
	pos = input_buf(buf, 'X', pos);
	bin = malloc(sizeof(char) * (32 + 1));
	bin = fill_bin(bin, n, is_neg, 32);
	hex = malloc(sizeof(char) * (8 + 1));
	hex = fill_hex(hex, bin, 1, 8);

	for (first = i = 0; hex[i]; i++)
	{
		if (hex[i] != '0' && first == 0)
			first = 1;
		if (first == 1)
		{
			pos = input_buf(buf, hex[i], pos);
			length++;
		}

	}
	free(bin);
	free(hex);

	return (length);
}

/**
 * print_lHEX - concatenates an upper hexadecimal to the buffer.
 *
 * @argument: the integer to turn hexadecimal.
 * @buf: the buffer.
 * @pos: the position to add on.
 *
 * Return: the length of the octal.
 */
int print_lHEX(va_list argument, char *buf, unsigned int pos)
{
	long int n, i, length, first, is_neg = 0;
	char *bin, *hex;

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
	hex = malloc(sizeof(char) * (16 + 1));
	hex = fill_hex(hex, bin, 1, 16);

	for (first = i = 0; hex[i]; i++)
	{
		if (hex[i] != '0' && first == 0)
			first = 1;
		if (first == 1)
		{
			pos = input_buf(buf, hex[i], pos);
			length++;
		}

	}
	free(bin);
	free(hex);
	return (length);
}

/**
 * print_sHEX - concatenates an upper hexadecimal to the buffer.
 *
 * @argument: the integer to turn hexadecimal.
 * @buf: the buffer.
 * @pos: the position to add on.
 *
 * Return: the length of the octal.
 */
int print_sHEX(va_list argument, char *buf, unsigned int pos)
{
	short int n, i, length, first, is_neg = 0;
	char *bin, *hex;

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
	hex = malloc(sizeof(char) * (4 + 1));
	hex = fill_hex(hex, bin, 1, 4);

	for (first = i = 0; hex[i]; i++)
	{
		if (hex[i] != '0' && first == 0)
			first = 1;
		if (first == 1)
		{
			pos = input_buf(buf, hex[i], pos);
			length++;
		}

	}
	free(bin);
	free(hex);
	return (length);
}
