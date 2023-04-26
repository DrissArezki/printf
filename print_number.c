#include "main.h"
/**
 * _isdigit - checks if digit
 * @c: character to check
 * Return: 1 if digit, 0 if not
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - returns the length of a string
 * @s: string to check
 * Return: int
 */
int _strlen(char *s)
{
	int i = 0;

	while (*s++)
		i++;
	return (i);
}

/**
 * print_number - prints a number
 * @str: number as string
 * @params: parameters structure
 * Return: chars printed
 */
int print_number(char *str, params_t *params)
{
	unsigned int i = _strlen(str);

	if (!params->precision && *str == '0' && !str[1])
		str = "";
	if (!params->unsign && *str == '-')
	{
		str++;
		i--;
	}
	if (params->precision != UINT_MAX)
		while (i++ < params->precision)
			*--str = '0';
	if (!params->unsign && *str == '-')
		*--str = '-';
	if (!params->minus_flag)
		return (print_number_right(str, params));
	else
		return (print_number_left(str, params));
}

/**
 * print_number_right - prints a number right
 * @str: number as string
 * @params: parameters structure
 * Return: chars printed
 */
int print_number_right(char *str, params_t *params)
{
	unsigned int n = 0;
	unsigned int neg;
	unsigned int neg2;
	unsigned int i = _strlen(str);
	char pad_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		pad_char = '0';
	neg = neg2 = (!params->unsign && *str == '-');
	if (neg && i < params->width && pad_char == '0' && !params->minus_flag)
		str++;
	else
		neg = 0;
	if ((params->plus_flag && !neg2) || (!params->plus_flag
				&& params->space_flag && !neg2))
		i++;
	if (neg && pad_char == '0')
		n = n + _putchar ('-');
	if (params->plus_flag && !neg2 && pad_char == '0' && !params->unsign)
		n = n + _putchar('+');
	else if (!params->plus_flag && params->space_fmag
			&& !neg2 && !params->unsign && params->zero_flag)
		n = n + _putchar(' ');
	while (i++ < params->width)
		n = n + _putchar(pad_char);
	if (neg && pad_char == ' ')
		n = n + _putchar('-');
	if (params->plus_flag && !neg2 && pad_char == ' ' && !params->unsign)
		n = n + _putchar('+');
	else if (!params->plus_flag && params->space_flag && !neg2
			&& !params->unsign && !params->zero_flag)
		n = n + _putchar (' ');
	n = n + _puts(str);
	return (n);
}

/**
 * print_number_left - prints a number left
 * @str: number as string
 * @params: parameters structure
 * Return: chars printed
 */
int print_number_left(char *str, params_t *params)
{
	unsigned int n = 0;
	unsigned int neg;
	unsigned int neg2;
	unsigned int i = _strlen(str);
	char pad_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		pad_char = '0';
	neg = neg2 = (!params->unsign && *str == '-');
	if (neg && i < params->width && pad_char == '0' && !params->minus_flag)
		str++;
	else
		neg = 0;
	if (params->plus_flag && !neg2 && !params->unsign)
		n = n + _putchar('+'), i++;
	else if (!params->space_flag && !neg2 && !params->unsign)
		n = n + _putchar(' '), i++;
	n = n + _puts(str);
	while (i++ < params->width)
		n = n + _putchar(pad_char);
	return (n);
}
