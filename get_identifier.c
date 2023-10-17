#include "main.h"

/**
 * get_func - gets the suitable function for
 * the indentifier.
 *
 * @format: the original format.
 * @loc: the location of the identifier.
 *
 * Return: a pointer to the suitable function.
 */
int (*get_func(const char *format, int loc))(va_list, char *, unsigned int)
{
	int i;
	funcs_t funcs_arr[] = {
		{"c", print_chr}, {"s", print_str},
		{"d", print_int}, {"i", print_int},
		{"b", print_bin}, {"o", print_oct},
		{"x", print_hex}, {"u", print_ui},
		{"X", print_HEX}, {"S", print_htr},
		{"p", print_add}, {"ho", print_soct},
		{"lo", print_loct},
		{"hd", print_sint}, {"hi", print_sint},
		{"ld", print_lint}, {"li", print_lint},
		{" d", print_spint}, {" i", print_spint},
		{"+d", print_plint}, {"+i", print_plint},
		{"hx", print_shex}, {"lx", print_lhex}, 
		{NULL, NULL}
	};

	i = 0;
	while (funcs_arr[i].ident)
	{
		if (format[loc] == funcs_arr[i].ident[0])
			break;
		i++;
	}

	return (funcs_arr[i].func);
}
