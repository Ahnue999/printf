#include "main.h"

/**
 * print_percent - Prints a percent sign
 *
 * @list: arguments
 * @buffer: Buffer array
 * @flags: active flags
 * @width: feild width.
 * @precision: precision specifier
 * @size: size specifier
 * Returm: percent sign
 */

int print_percent(va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(list);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}
