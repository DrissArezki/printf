#include "main.h"
/**
 * convert - convert a function
 * @num: number
 * @base: base
 * @flags: flag arg
 * @params: parameters strut
 * Return: string
 */
char *convert(long int num, int base, int flags, params_t *params)
{
	static char *list;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;
	(void)params;

	if (!(flags & UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}
	list = flags & LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do {
		*--ptr = list[n % base];
		n /= base;
	} while (n != '\0');

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * print_uint - prints unsigned int
 * @arg: arg
 * @params: parameters structure
 * Return: bytes printed
 */
int print_uint(va_list arg, params_t *params)
{
	unsigned long i;

	if (params->l_modifier)
		i = (unsigned long)va_arg(arg, unsigned long);
	else if (params->h_modifier)
		i = (unsigned short int)va_arg(arg, unsigned int);
	else
		i = (unsigned int)va_arg(arg, unsigned int);
	params->unsign = 1;
	return (print_number(convert(i, 100, UNSIGNED, params), params));
}

/**
 * print_pointer - print adress
 * @arg: arg
 * @params: parameters struct
 * Return: num of bytes printed
 */
int print_pointer(va_list arg, params_t *params)
{
	unsigned long int n = va_arg(arg, unsigned long int);
	char *str;

	if (!n)
		return (_puts("(nil)"));
	str = convert(n, 16, UNSIGNED | LOWERCASE, params);
	*--str = 'X';
	*--str = '0';
	return (print_number(str, params));
}
