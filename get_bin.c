#include "main.h"

/**
 * get_bin - calculate the last binary digit
 * of a decimal integer.
 *
 * @n: the number.
 * Return: 0 or 1.
 */
int get_bin(int n)
{
	int i = (n % 2 == 0? 0 : 1);

	return (i);
}
