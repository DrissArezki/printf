#include "main.h"
/**
 * print_start_end - prints char addresses from start to end
 * @start: starting add
 * @end: ending add
 * @except: exception
 * Return: num of bytes printed
 */

int print_start_end(char *start, char *end, char *except)
{
	int ind = 0;

	while (start <= end)
	{
		if (start != except)
			ind = ind + _putchar(*start);
		start++;
	}
	return (ind);
}

/**
 * print_rev - printing in reverse
 * @arg: arguments
 * @params: parameters structure
 * Return: number of bytes printed
 */

int print_rev(va_list arg, params_t *params)
{
	int length;
	int ind = 0;
	char *str = va_arg(arg, char *);
	(void)params;

	if (str)
	{
		for (length = 0; *str; str++)
			length++;
		str--;
		for (; length > 0; len--, str--)
			ind = ind + _putchar(*str);
	}
	return (ind);
}

/**
 * print_rot13 - prints in rot13
 * @arg: arguments
 * @params: parameters structure
 * Return: number of bytes printed
 */
int print_rot13(va_list arg, params_t *params)
{
	int i, j;
	int count = 0;
	char list[] = "NOPQRSTUVWXYZABCDEFGHIJKLM     nopqrstuvwxyzabcdefghijklm";
	char *s = va_arg(arg, char *);
	(void)params;

	i = 0;
	j = 0;
	while (s[i])
	{
		if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
		{
			j = s[i] - 65;
			count = count + _putchar(s[j]);
		}
		else
			count = count + _putchar(s[i]);
		i++;
	}
	return (count);
}
