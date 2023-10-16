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
	int i, printed_ch = 0, pos = 0, str_len;
	va_list list;
	char *buf;
	int (*func)(va_list, char *, unsigned int);

	buf = malloc(sizeof(char) * BUFSIZE);
	if (buf == NULL || format == NULL)
		return(-1);

	va_start(list, format);
	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				break;
			else if (format[i + 1] == '%')
			{
				pos = input_buf(buf, format[i + 1], pos);
				printed_ch++;
			}
			else
			{
				func = get_func(format, i + 1);
				if (func == NULL)
					return (-1);
				else
				{
					pos += func(list, buf, pos);
					printed_ch++;
				}
			}
			i++;
			/*else if (*format == 's')
			{
				char *str = va_arg(list, char *);

				str_len = 0;

				while (str[str_len] != '\0')
					str_len++;
				write(1, str, str_len);
				printed_ch += str_len;
			}*/
		}
		else
		{
			pos = input_buf(buf, format[i], pos);
			printed_ch++;
		}
	}

	print_buf(buf, pos);
	free(buf);
	va_end(list);

	return (printed_ch);
}
