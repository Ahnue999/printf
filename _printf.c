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
	int printed_ch = 0;
	va_arg list;

	if (*format == NULL)
		return (-1);

	va_start(list, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			printed_ch++;
		}
		else
		{
			format++
			if (*format == '\0')
				break;
			else if (*format == '%')
			{
				write(1, format, 1);
				printed_ch++;
			}
			else if (*format == 'c')
			{
				char c = va_arg(list, int);

				write(1, &c, 1);
				printed_ch++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(list, *char);

				str_len = 0;

				while (str[str_len] != '\0')
					str_len++;
				write(1, str, str_len);
				printed_ch += str_len;
			}
		}

		format++;
	}

	va_end(list);

	return (printed_ch);
}
