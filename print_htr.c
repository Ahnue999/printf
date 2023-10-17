#include "main.h"

/**
  * print_htr - prints a string and change non-printable
  * characters into their perspective hexadecimal ASCII.
  *
  * @argument: the string.
  * @buf: the buffer.
  * @pos: the position to add on
  *
  * Return: the length of the string.
  */
int print_htr(va_list argument, char *buf, unsigned int pos)
{
	unsigned int i, length, op;
	char *bin, *hex, *str;

	str = va_arg(argument, char *);
	bin = malloc(sizeof(char) * (31 + 1));
	hex = malloc(sizeof(char) * (8 + 1));

	for (length = i = 0; str[i]; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			pos = input_buf(buf, '\\', pos);
			pos = input_buf(buf, 'x', pos);
			op = str[i];
			bin = fill_bin(bin, op, 0, 32);
			hex = fill_hex(hex, bin, 1, 8);
			pos = input_buf(buf, hex[6], pos);
			pos = input_buf(buf, hex[7], pos);
			length += 3;
		}
		else
			pos = input_buf(buf, str[i], pos);
	}
	free(bin);
	free(hex);
	return (length + i);
}
