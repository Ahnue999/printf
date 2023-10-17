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
	unsigned int i;
	char *nil = "(null)";

	s = va_arg(list, char *);

	if (s == NULL)
	{
		for (i = 0; nil[i]; i++)
			pos = input_buf(buf, nil[i], pos);
		return (i);
	}

	for (i = 0; s[i]; i++)
		pos = input_buf(buf, s[i], pos);

	return (i);
}
