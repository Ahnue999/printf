#include "main.h"

/*
 * get_func - gets the suitable function for
 * the indentifier.
 *
 * @format: the original format.
 * @location: the location of the identifier.
 * 
 * Return: a pointer to the suitable function.
 */
int (*get_func(const char *format, int location))(va_list, char *, unsigned int)
{
	int i;
	funcs_t funcs_arr[] = {
		{"c", print_char},
		{"s", print_str},
		{"d", print_dec},
		{"i", print_dec},
		{"b", print_bin},
		{"u", print_ui},
		{NULL, NULL}
	};

	i = 0;
	while (funcs_arr[i].ident)
	{
		if (format[location] == funcs_arr[i].ident[0])
			break;
		i++;
	}

	return (funcs_arr[i].func);
}
