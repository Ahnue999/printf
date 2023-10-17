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

/**
 * print_rev - concatenates the provided string
 * to the buffer in reverse.
 *
 * @list: contains the string to add.
 * @buf: the buffer.
 * @pos: the position to concatenate to.
 * Return: the length of the printed string.
 */
int print_rev(va_list list, char *buf, unsigned int pos)
{
	char *s;
	unsigned int i; 
	int j = 0;
	char *nil = "(null)";

	s = va_arg(list, char *);

	if (s == NULL)
	{
		for (i = 0; nil[i]; i++)
			pos = input_buf(buf, nil[i], pos);
		return (i);
	}

	for (i = 0; s[i]; i++)
		;
	j = i - 1;
	for (; j >= 0; j--)
		pos = input_buf(buf, s[i], pos);

	return (i);
}

/**
 * print_rot - concatenates the string in ROT13
 * @arguments: string
 * @buf: the buffer
 * @pos: the position to add on.
 * Return: number of chars printed.
 */
int print_rot(va_list arguments, char *buf, unsigned int pos)
{
	char alf[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rot[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char *str;
	unsigned int i, j, k;
	char nill[] = "(avyy)";

	str = va_arg(arguments, char *);
	if (str == NULL)
	{
		for (i = 0; nill[i]; i++)
			pos = input_buf(buf, nill[i], pos);
		return (6);
	}
	for (i = 0; str[i]; i++)
	{
		for (k = j = 0; alf[j]; j++)
		{
			if (str[i] == alf[j])
			{
				k = 1;
				pos = input_buf(buf, rot[j], pos);
				break;
			}
		}
		if (k == 0)
			pos = input_buf(buf, str[i], pos);
	}
	return (i);
}
