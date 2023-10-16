#include "main.h"

int input_buf(char *buf, char c, unsigned int pos)
{
	if (pos == BUFSIZE)
	{
		print_buf(buf, pos);
		pos = 0;
	}
	buf[pos] = c;
	pos++;
	return (pos);
}

