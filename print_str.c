#include "main.h"

/**
 * print_str - concatenates the provided string
 * to the buffer.
 *
 * @list: contains the string to add.
 * @buf: the buffer.
 * @pos: the position to concatenate to.
 * Return: the length of the printed string.
 */
int print_str(va_list list, char *buf, unsigned int pos)
{
	char *s;
	int i;

	s = va_arg(list, char *);

	i = 0;
	while (s[i])
	{
		pos = input_buf(buf, s[i], pos);
		i++;
	}

	return (i);
}
