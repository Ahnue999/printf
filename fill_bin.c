#include "main.h"

/**
  * fill_bin - fills an array with the binary of n.
  *
  * @bin: the binary array to fill.
  * @n: the input number in decimal.
  * @is_neg: wheither the dec is neg or not.
  * @limit: the slots available the array
  *
  * Return: a pointer to the array.
  */
char *fill_bin(char *bin, int n, int is_neg, int limit)
{
	int i;

	for (i = 0; i < limit; i++)
		bin[i] = '0';
	bin[limit] = '\0';

	for (i = limit - 1; n > 1; i--)
	{
		if (n % 2 == 0)
			bin[i] = '0';
		else
			bin[i] = ('0' + 1);
		n /= 2;
	}

	if (n != 0)
		bin[i] = '1';

	if (is_neg)
	{
		for (i = 0; bin[i]; i++)
		{
			if (bin[i] == '0')
				bin[i] = '1';
			else
				bin[i] = '0';
		}
	}
	return (bin);
}
