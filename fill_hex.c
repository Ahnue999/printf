#include "main.h"

/**
  * fill_hex - fills an array with the hex of n.
  *
  * @hex: the hex array to fill.
  * @bin: the binary form of the decimal
  * @isupper: upper or lower
  * @limit: the slots available the array.
  * Return: a pointer to the array.
  */
char *fill_hex(char *hex, char *bin, int isupper, int limit)
{
	int i, j, op, letter;

	hex[limit] = '\0';

	if (isupper)
		letter = 55;
	else
		letter = 87;

	for (i = (limit * 4) - 1; i >= 0; i--)
	{
		for (op = 0, j = 1; j <= 8; i--, j *= 2)
			op = ((bin[i] - '0') * j) + op;
		i++;
		if (op < 10)
			hex[i / 4] = op + '0';
		else
			hex[i / 4] = op + letter;
	}
	return (hex);
}
