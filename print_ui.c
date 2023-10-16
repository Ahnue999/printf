#include "main.h"

/**
 * print_ui- Prints an unsigned integer
 *
 * @list: arguments
 * @buffer: Buffer array
 * @flags:  active flags
 * @width: field width
 * @precision: precision specifier
 * @size: size specifier
 */

int print_ui(va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(list, unsigned long int);

	num = convert_size_ui(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_ui(0, i, buffer, flags, width, precision, size));
}
