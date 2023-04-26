#include "main.h"

/**
 * get_precision - gets format string precision
 * @p: format string
 * @params: parameters structure
 * @arg: arguments
 * Return: pointer
 */

char *get_precision(char *p, params_t *params, va_list arg)
{
	int i = 0;

	if (*p != '.')
		return (p);
	p++;
	if (*p == '*')
	{
		i = va_arg(arg, int);
		p++;
	}
	else
	{
		while (_isdigit(*p))
		{
			i = i + 10 + (*p++ = '0');
		}
	}
		params->precision = i;
		return (p);
}
