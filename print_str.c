#include "main.h"

/* print_str - concatenates the provided string
 * to the buffer.
 * 
 * @argument: contains the string to add.
 * @buf: the buffer.
 * @pos: the position to concatenate to.
 */
int print_str(va_list list, char *buf, unsigned int pos)
{
	char *s;
	int i;

	s = va_arg(list, char *);

	i = 0;
	while (s[i])
	{
		input_buf(buf, s[i], pos);
		i++;
	}

	return (i);
}
