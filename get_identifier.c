#include "main.h"

/**
 * get_func - gets the suitable function for
 * the indentifier.
 *
 * @format: original format.
 * @loc: location of the identifier.
 *
 * Return: a pointer to the suitable function.
 */
int (*get_func(const char *format, int loc))(va_list, char *, unsigned int)
{
	int i = 0, j = 0, first;
	funcs_t funcs_arr[] = {
		{"c", print_chr}, {"s", print_str},
		{"d", print_int}, {"i", print_int},
		{"b", print_bin}, {"o", print_oct},
		{"x", print_hex}, {"u", print_ui},
		{"X", print_HEX}, {"S", print_htr},
		{"p", print_add}, {"ho", print_soct},
		{"hd", print_sint}, {"hi", print_sint},
		{"ld", print_lint}, {"li", print_lint},
		{" d", print_spint}, {" i", print_spint},
		{"+d", print_plint}, {"hx", print_shex},
		{"lx", print_lhex}, {" u", print_ui},
		{" o", print_oct}, {"#i", print_int},
		{"#d", print_int}, {"lo", print_loct},
		{" x", print_hex}, {"%", print_per},
		{"+i", print_plint}, {"+d", print_plint},
		{"+u", print_ui}, {"+o", print_oct},
		{"+x", print_hex}, {"+X", print_HEX},
		{"lx", print_shex}, {"lX", print_lHEX},
		{"R", print_rot}, {"r", print_rev},
		{" +i", print_plint}, {" +d", print_plint},
		{"+ i", print_plint}, {"+ d", print_plint},
		{"#o", print_noct}, {"#x", print_nhex},
		{"#X", print_NHEX}, {"#u", print_ui},
		{NULL, NULL}
	};

	first = loc;
	while (funcs_arr[i].ident)
	{
		if (format[loc] == funcs_arr[i].ident[j])
		{
			if (funcs_arr[i].ident[j + 1] != '\0')
				loc++, j++;
			else
				break;
		}
		else
		{
			i++;
			j = 0;
			loc = first;
		}
	}

	return (funcs_arr[i].func);
}
