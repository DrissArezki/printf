#include "main.h"

/**
 * get_spec - finds the format spec
 * @s: format
 * Return: number of printed chars
 */

int (*get_spec(char *s))(va_list arg, params_t *params)
{
	spec_t spec[] = {
		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
		{"s", print_string},
		{"b", print_binary},
		{"u", print_uint},
		{"o", print_oct},
		{"x", print_hex},
		{"X", print_HEX},
		{"S", print_S},
		{"p", print_pointer},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL}
	};

	int n = 0;

	while (spec[i].spec)
	{
		if (*s == spec[i].spec[0])
			return (spec[i].f);
		i++;
	}
	return (NULL);
}

/**
 * print_func - checks the format func
 * @s: format string
 * @arg: argumetns used
 * @params: parameters structure
 * Return: number of bytes printed
 */

int print_func(char *s, va_list arg, params_t *params)
{
	int (*f)(va_list, params_t *) = get_spec(s);

	if (f)
		return (f(arg, params));
	return (0);
}

/**
 * get_flag - finds the flag
 * @s: format string
 * @params: parameters structure
 * Return: if flag exists
 */

int get_flag(char *s, params_t *params)
{
	int i = 0;

	switch (*s)
	{
		case '+':
			i = params->plus_flag = 1;
			break;
		case ' ':
			i = params->space_flag = 1;
			break;
		case '-':
			i = params->minus_flag = 1;
			break;
		case '#':
			i = params->hashtag_flag = 1;
			break;
		case '0':
			i = params->zero_flag = 1;
			break;
	}
	return (i);
}

/**
 * get_modifier - finds modififer function
 *@s: format string
 * @params: parameters structure
 * Return: if modifier exists
 */
int get_modifier(char *s, params_t *params)
{
	int i = 0;

	switch (*s)
	{
		case 'h':
			i = params->h_modifier = 1;
			break;
		case 'l':
			i = params->l_modifier = 1;
			break;
	}
	return (i);
}

/**
 * get_width - gets the width of the format string
 * @s: format string
 * @params: parameters structure
 * @arg: arguments
 * Return: pointer
 */
char *get_width(char *s, params_t *params, va_list arg)
{
	int i = 0;

	if (*s == '*')
	{
		i = va_arg(arg, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			i = i * 10 + (*s++ - '0');
	}
	params->width = i;
	return (s);
}
