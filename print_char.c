#include "main.h"

/* print_char - concatenates the provided char
 * to the buffer.
 * 
 * @argument: contains the char to add.
 * @buf: the buffer.
 * @pos: the position to concatenate to.
 */
int print_char(va_list list, char *buf, unsigned int pos)
{
	char c;

	c = va_arg(list, int);
	input_buf(buf, c, pos);

	return (1);
}