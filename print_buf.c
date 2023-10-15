#include "main.h"

int print_buf(char *c, int pos)
{
	return(write(1, c, pos));
}
