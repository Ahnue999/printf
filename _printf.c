#include "main.h"

/**
 * _printf - a function that prints output on the screen
 *
 * @format: format string
 *
 * Return: the number of characters printed.
 */
int _printf(const char *format, ...)
{
	unsigned int i = 0, ch = 0, pos = 0;
	va_list list;
	char *buf;
	int (*func)(va_list, char *, unsigned int);

	va_start(list, format);

	buf = malloc(sizeof(char) * BUFSIZE);
	if (!format || (format[i] == '%' && !format[i + 1]) || !buf)
		return (-1);
	if (!format[i])
		return (0);


	for (i = 0; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
			{
				print_buf(buf, pos), free(buf), va_end(list);
				return (-1);
			}
			else
			{
				func = get_func(format, i + 1);
				if (func == NULL)
				{
					if (format[i + 1] == ' ' && !format[i + 2])
						return (-1);
					input_buf(buf, format[i], pos), ch++, i--;
				}
				else
				{
					ch += func(list, buf, pos);
					i += ev_print_func(format, i + 1);
				}
			} i++;
		}
		else
			input_buf(buf, format[i], pos), ch++;
		for (pos = ch; pos > BUFSIZE; pos -= BUFSIZE)
			;
	}

	print_buf(buf, pos);
	free(buf);
	va_end(list);

	return (ch);
}
