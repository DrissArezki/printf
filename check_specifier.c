#include "main.h"
/*
 * check_specifier - check if character is a vaild specifier and
 * assign an a funtion for its printing
 * @format: specifier type (char*)
 * return: pointer to function
 */
int (*(check_specifier(const char *format)))(va_list)
{
	int i;

	func_t my_array[4] = {
		{"c", print_char},
		{"s", print_str},
		{"%", print_cent},
		{NULL, NULL}};

	for (i = 0; my_array[i].t != NULL; i++)
	{
		if ((*my_array[i].t) == *format)
		{
			return (my_array[i].f);
		}
	}
	return (NULL);
}
