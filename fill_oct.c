#include "main.h"

/**
  * fill_oct - fills an array with the octal of n.
  *
  * @oct: the octal array to fill.
  * @bin: the binary form of the decimal
  * Return: a pointer to the array.
  */
char *fill_oct(char *oct, char *bin)
{
	int ibin, j, op, ioct, limit;

	oct[11] = '\0';

	for (ibin = 31, ioct = 10; ibin >= 0; ibin--, ioct--)
	{
		if (ibin > 1)
			limit = 4;
		else
			limit = 2;
		for (op = 0, j = 1; j <= limit; ibin--, j *= 2)
			op = ((bin[ibin] - '0') * j) + op;
		ibin++;
		oct[ioct] = op + '0';
	}
	return (oct);
}

/**
  * fill_soct - fills an array with the octal of n.
  *
  * @oct: the octal array to fill.
  * @bin: the binary form of the decimal
  * Return: a pointer to the array.
  */
char *fill_soct(char *oct, char *bin)
{
	int ibin, j, op, ioct, limit;

	oct[6] = '\0';

	for (ibin = 15, ioct = 5; ibin >= 0; ibin--, ioct--)
	{
		if (ibin > 1)
			limit = 4;
		else
			limit = 1;
		for (op = 0, j = 1; j <= limit; ibin--, j *= 2)
			op = ((bin[ibin] - '0') * j) + op;
		ibin++;
		oct[ioct] = op + '0';
	}
	return (oct);
}

/**
  * fill_loct - fills an array with the octal of n.
  *
  * @oct: the octal array to fill.
  * @bin: the binary form of the decimal
  * Return: a pointer to the array.
  */
char *fill_loct(char *oct, char *bin)
{
	int ibin, j, op, ioct, limit;

	oct[22] = '\0';

	for (ibin = 63, ioct = 21; ibin >= 0; ibin--, ioct--)
	{
		if (ibin > 1)
			limit = 4;
		else
			limit = 1;
		for (op = 0, j = 1; j <= limit; ibin--, j *= 2)
			op = ((bin[ibin] - '0') * j) + op;
		ibin++;
		oct[ioct] = op + '0';
	}
	return (oct);
}
