#include "main.h"

/**
 * get_size - gets size
 *
 * @format: Format string
 * @i: arguments
 *
 * Return: size
 */

int get_size(const char *format, int *i)
{
	int j = *i + 1;
	int size = 0;

	if (format[j] == 'l')
		size = S_LONG;
	else if (format[j] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = j - 1;
	else
		*i = j;

	return (size);
}

/**
 * get_width - gets width
 *
 * @format: string format
 * @i: arguments
 * @list: list of arguments
 *
 * Return: width
 */

int get_width(const char *format, int *i, va_list list)
{
	int j;
	int width = 0;

	for (j = *i + 1; format[j] != '\0'; j++)
	{
		if (is_digit(format[j]))
		{
			width *= 10;
			width += format[j] - '0';
		}
		else if (format[j] == '*')
		{
			j++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = j - 1;

	return (width);
}



/**
 * get_precision - gets precision
 * @format: format string
 * @i: arguments
 * @list: list
 *
 * Return: Precision.
 */

int get_precision(const char *format, int *i, va_list list)
{
	int j = *i + 1;
	int precision = -1;

	if (format[j] != '.')
		return (precision);

	precision = 0;

	for (j += 1; format[j] != '\0'; j++)
	{
		if (is_digit(format[j]))
		{
			precision *= 10;
			precision += format[j] - '0';
		}
		else if (format[j] == '*')
		{
			j++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = j - 1;

	return (precision);
}

/**
 * get_flags - gets active flags
 * @format: string formar
 * @i: input
 *
 * Return: Flags
 */
int get_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, j;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (j = *i + 1; format[j] != '\0'; j++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[j] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}

		if (FLAGS_CH[j] == 0)
			break;
	}

	*i = j - 1;

	return (flags);
}
