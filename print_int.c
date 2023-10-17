#include "main.h"

/**
 * print_int - concatenate a decimal to the
 * buffer.
 *
 * @argument: the decimal.
 * @buf: the buffer.
 * @pos: the positiong to concatenate to.
 *
 * Return: The length of the decimal added.
 */
int print_int(va_list argument, char *buf, unsigned int pos)
{
	int n;
	unsigned int i, count, d, m, tmp, is_neg = 0;

	n = va_arg(argument, int);

	if (n < 0)
	{
		pos = input_buf(buf, '-', pos);
		m = n * -1;
		is_neg = 1;
	}
	else
		m = n;

	d = m;
	count = 1;
	while (d > 9)
	{
		d /= 10;
		count *= 10;
	}

	for (i = 0; count > 0; count /= 10, i++)
	{
		tmp = ((m / count) % 10);
		pos = input_buf(buf, ('0' + tmp), pos);
	}

	return (i + is_neg);
}

/**
 * print_plint - concatenate a decimal to the
 * buffer (with either a + or - sign.
 *
 * @argument: the decimal.
 * @buf: the buffer.
 * @pos: the positiong to concatenate to.
 *
 * Return: The length of the decimal added.
 */
int print_plint(va_list argument, char *buf, unsigned int pos)
{
	int n;
	unsigned int i, count, d, m, tmp;

	n = va_arg(argument, int);

	if (n < 0)
	{
		pos = input_buf(buf, '-', pos);
		m = n * -1;
	}
	else
	{
		m = n;
		pos = input_buf(buf, '-', pos);
	}

	d = m;
	count = 1;
	while (d > 9)
	{
		d /= 10;
		count *= 10;
	}

	for (i = 0; count > 0; count /= 10, i++)
	{
		tmp = ((m / count) % 10);
		pos = input_buf(buf, ('0' + tmp), pos);
	}

	return (i + 1);
}
/**
 * print_spint - concatenate a decimal to the
 * buffer (with minus sign or a space instead.
 *
 * @argument: the decimal.
 * @buf: the buffer.
 * @pos: the positiong to concatenate to.
 *
 * Return: The length of the decimal added.
 */
int print_spint(va_list argument, char *buf, unsigned int pos)
{
	int n;
	unsigned int i, count, d, m, tmp;

	n = va_arg(argument, int);

	if (n < 0)
	{
		pos = input_buf(buf, '-', pos);
		m = n * -1;
	}
	else
	{
		pos = input_buf(buf, ' ', pos);
		m = n;
	}

	d = m;
	count = 1;
	while (d > 9)
	{
		d /= 10;
		count *= 10;
	}

	for (i = 0; count > 0; count /= 10, i++)
	{
		tmp = ((m / count) % 10);
		pos = input_buf(buf, ('0' + tmp), pos);
	}

	return (i + 1);
}


/**
 * print_lint - concatenate a decimal to the
 * buffer.
 *
 * @argument: the decimal.
 * @buf: the buffer.
 * @pos: the positiong to concatenate to.
 *
 * Return: The length of the decimal added.
 */
int print_lint(va_list argument, char *buf, unsigned int pos)
{
	long int n;
	unsigned long int i, count, d, m, tmp, is_neg = 0;

	n = va_arg(argument, long int);

	if (n < 0)
	{
		pos = input_buf(buf, '-', pos);
		m = n * -1;
		is_neg = 1;
	}
	else
		m = n;

	d = m;
	count = 1;
	while (d > 9)
	{
		d /= 10;
		count *= 10;
	}

	for (i = 0; count > 0; count /= 10, i++)
	{
		tmp = ((m / count) % 10);
		pos = input_buf(buf, ('0' + tmp), pos);
	}

	return (i + is_neg);
}


/**
 * print_sint - concatenate a decimal to the
 * buffer.
 *
 * @argument: the decimal.
 * @buf: the buffer.
 * @pos: the positiong to concatenate to.
 *
 * Return: The length of the decimal added.
 */
int print_sint(va_list argument, char *buf, unsigned int pos)
{
	short int n;
	unsigned short int i, count, d, m, tmp, is_neg = 0;

	n = va_arg(argument, int);

	if (n < 0)
	{
		pos = input_buf(buf, '-', pos);
		m = n * -1;
		is_neg = 1;
	}
	else
		m = n;

	d = m;
	count = 1;
	while (d > 9)
	{
		d /= 10;
		count *= 10;
	}

	for (i = 0; count > 0; count /= 10, i++)
	{
		tmp = ((m / count) % 10);
		pos = input_buf(buf, ('0' + tmp), pos);
	}

	return (i + is_neg);
}
