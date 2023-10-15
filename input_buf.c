#include "main.h"

int input_buf(char *buffer, char c, unsigned int pos)
{
	buffer[pos] = c;
	pos++;
	return (pos);
}

