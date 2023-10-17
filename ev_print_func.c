#include "main.h"

/**
 * ev_print_func - returns the amount of identifiers.
 * @s: argument indentifier
 * @index: index of argument identifier.
 * Return: amount of identifiers.
 */
int ev_print_func(const char *s, int index)
{
	 funcs_t pr[] = {
		{"c", print_chr}, {"s", print_str}, {"i", print_int},
		{"d", print_int}, {"b", print_bin}, {"u", print_ui},
		{"o", print_oct}, {"x", print_hex}, {"x", print_hex},
		{"S", print_htr}, {"p", print_add}, {"ho", print_soct},
		{"lo", print_loct}, {"hd", print_sint}, {"hi", print_sint},
		{"ld", print_lint}, {"li", print_lint}, {" d", print_spint},
		{" i", print_spint}, {"+d", print_plint}, {"+i", print_plint},
		{"hx", print_shex}, {"lx", print_lhex}, {"%", print_per},
		{" u", print_ui}, {" o", print_oct}, {" x", print_hex},
		{"#i", print_int}, {"#d", print_int}, {"lx", print_shex},
		{"lX", print_lHEX}, 
		{NULL, NULL},
	};
	int i = 0, j = 0, first_index;

	first_index = index;
	while (pr[i].ident)
	{
		if (s[index] == pr[i].ident[j])
		{
			if (pr[i].ident[j + 1] != '\0')
				index++, j++;
			else
				break;
		}
		else
		{
			j = 0;
			i++;
			index = first_index;
		}
	}
	return (j);
}
