#include "main.h"

/**
 *
 *
 *
 *
 * Return: the number of characters printed. 
 */
int _printf(const char *format, ...)
{
	int i, pos = 0;
	char *buf;

	buf = malloc(sizeof(char) * BUFSIZE);
	if (buf == NULL)
		return (-1);

	i = 0;
	while (format[i])
	{
		/*if (format[i] == %)
		 * {
		 * }
		 * else
		 * */
			pos = input_buf(buf, format[i], pos);
			i++;
	}
	print_buf(buf, pos);
	free(buf);
	return (pos);
}
