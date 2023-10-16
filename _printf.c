#include "main.h"

void buffer_output(char buffer[], int *buff_index);


/**
 * _printf - a function that prints output on the screen
 *
 * @format: format string
 *
 * Return: the number of characters printed.
 */

int _printf(const char *format, ...)
{
	char buffer[BUFF_SIZE];
	int i, output = 0, printed_ch = 0;
	int flags, width, precision, size, buff_index = 0;
	va_list list;

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_index++] = format[i];
			if (buff_index == BUFF_SIZE)
				buffer_output(buffer, &buff_index);

			printed_ch++;
		}
		else
		{
			buffer_output(buffer, &buff_index);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			output = print_output(format, &i, list, buffer,
				flags, width, precision, size);
			if (output == -1)
				return (-1);
			printed_ch += output;
		}
	}

	buffer_output(buffer, &buff_index);

	va_end(list);

	return (printed_ch);
}


/**
 * buffer_output - prints the output of the buffer to the screen
 *
 * @buffer: Array of chars of the buffer
 * @buff_index: buffer index
 */

void buffer_output(char buffer[], int *buff_index)
{
	if (*buff_index > 0)
		write(1, &buffer[0], *buff_index);

	*buff_index = 0;
}
