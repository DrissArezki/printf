#include "main.h"
/**
 * print_char - prints a character
 * @arg: arg
 * @params: parameteres structure
 * Return: number of chars
 */
int print_char(va_list arg, params_t *params)
{
	char pad_char = ' ';
	unsigned int pad = 1;
	unsigned int ind = 0;
	unsigned int ch = va_arg(arg, int);

	if (params->minus_flag)
		ind = ind + _putchar(ch);
	while (pad++ < params->width)
		ind = ind + _putchar(pad_char);
	if (!params->minus_flag)
		ind = ind + _putchar(ch);
	return (ind);
}
/**
 * print_int - prints an int
 * @arg: arg
 * @params: parameteres structure
 * Return: number of ints
 */
int print_int(va_list arg, params_t *params)
{
	long l;

	if (params->l_modifier)
		l = va_arg(arg, long);
	else if (params->h_modifier)
		l = (short int)va_arg(arg, int);
	else
		l = (int)va_arg(arg, int);
	return (print_number(convert(l, 10, 0, params), params));
}
/**
 * print_string - prints string
 * @arg: arg
 * @params: parameteres structure
 * Return: number of strings
 */
int print_string(va_list arg, params_t *params)
{
	char *str = va_arg(arg, char *);

	pad_char = ' ';

	unsigned int pad = 0;
	unsigned int ind = 0;
	unsigned int i = 0;
	unsigned int j;

	(void)params;
	switch ((int)(!str))
	case 1:
		str = NULL_STRING;

	j = pad = _strlen(str);
	if (params->precision < pad)
		j = pad = params->precision;

	if (params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				ind = ind + _putchar(*str++);
		else
			ind = ind + _puts(str);
	}
	while (j++ < params->width)
		ind = ind + _putchar(pad_char);
	if (!params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				ind = ind + _putchar(*str++);
		else
			ind = ind + _puts(str);
	}
	return (ind);
}

/**
 * print_default - prints %
 * @arg: arg
 * @params: parameteres structure
 * Return: %
 */
int print_default(va_list arg, params_t *params)
{
	(void)arg;
	(void)params;
	return (_putchar('%'));
}

/**
 * print_S - prints custom string
 * @arg: arg
 * @params: parameteres structure
 * Return: custom string
 */
int print_S(va_list arg, params_t *params)
{
	char *str = va_arg(arg, char *);
	char *ptr;
	int ind = 0;

	if ((int)(!str))
		return (_puts(NULL_STRING));
	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			ind = ind + _putchar('\\');
			ind = ind + _putchar('X');
			ptr = convert(*str, 16, 0, params);
			if (!ptr[1])
				ind = ind + _putchar('\0');
			ind = ind + _puts(ptr);
		}
		else
			ind = ind + _putchar(*str);
	}
	return (ind);
}
