#include "main.h"

/**
  * input_buf - inserts a character on the buffer.
  *
  * @buf: the buffer.
  * @c: the character to insert.
  * @pos: the position to insert into;
  * Return: The new position.
  */
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

