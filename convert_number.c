#include "main.h"
/**
 * print_hex - prints unsigned hex in lowercase
 * @arg: arg
 * @params: parameters structure
 * Return: num if bytes printed
 */
int print_hex(va_list arg, params_t *params)
{
	unsigned long i;
	int j = 0;
	char *str;

	if (params->l_modifier)
		i = (unsigned long)va_arg(arg, unsigned long);
	else if (params->h_modifier)
		i = (unsigned short int)va_arg(arg, unsigned int);
	else
		i = (unsigned int)va_arg(arg, unsigned int);

	str = convert(i, 16, UNSIGNED | LOWERCASE, params);
	if (params->hashtag_flag && i)
	{
		*--str = 'x';
		*--str = '0';
	}
	params->unsign = 1;
	return (j = j + print_number(str, params));
}

/**
 * print_HEX - prints unsigned hex in uppercase
 * @arg: arg
 * @params: parameters structure
 * Return: num if bytes printed
 */
int print_HEX(va_list arg, params_t *params)
{
	unsigned long i;
	int j = 0;
	char *str;

	if (params->l_modifier)
		i = (unsigned long)va_arg(arg, unsigned long);
	else if (params->h_modifier)
		i = (unsigned short int)va_arg(arg, unsigned int);
	else
		i = (unsigned int)va_arg(arg, unsigned int);

	str = convert(i, 16, UNSIGNED, params);
	if (params->hashtag_flag && i)
	{
		*--str = 'X';
		*--str = '0';
	}
	params->unsign = 1;
	return (j = j + print_number(str, params));
}

/**
 * print_binary - print unsigned binary number
 * @arg: arg
 * @params: parameters structure
 * Return: num if bytes printed
 */

int print_binary(va_list arg, params_t *params)
{
	unsigned int i = va_arg(arg, unsigned int);
	char *str = convert(i, 2, UNSIGNED, params);
	int j = 0;

	if (params->hashtag_flag && i)
		*--str = '0';
	params->unsign = 1;
	return (j = j + print_number(str, params));
}

/**
 * print_oct - prints unsigned oct
 * @arg: arg
 * @params: parameters structure
 * Return: num if bytes printed
 */
int print_oct(va_list arg, params_t *params)
{
	unsigned long i;
	int j = 0;
	char *str;

	if (params->l_modifier)
		i = (unsigned long)va_arg(arg, unsigned long);
	else if (params->h_modifier)
		i = (unsigned short int)va_arg(arg, unsigned int);
	else
		i = (unsigned int)va_arg(arg, unsigned int);

	str = convert(i, 8, UNSIGNED, params);
	if (params->hashtag_flag && i)
		*--str = '0';
	params->unsign = 1;
	return (j = j + print_number(str, params));
}
