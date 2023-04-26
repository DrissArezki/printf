#include "main.h"

/**
 * _printf - prints anything
 * @format: format string
 * Return: number of bytes printed
 */

int _printf(const char *format, ...)
{
	int ind = 0;
	va_list arg;
	char *p, *start;
	params_t params = INIT_CONFIG;

	va_start(arg, format);

	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	for (p = (char *)format; *p; p++)
	{
		init_params(&params, arg);
		if (*p != '%')
		{
			ind = ind + _putchar(*p);
			continue;
		}
		start = p;
		p++;
		while (get_flag(p, &params))
			p++;
		p = get_width(p, &params, arg);
		p = get_precision(p, &params, arg);
		if (get_modifier(p, &params))
			p++;
		if (!get_spec(p))
			ind = ind + print_start_end(start, p,
					params.l_modifier || params.h_modifier ? p - 1 : 0);
		else
			ind = ind + print_func(p, arg, &params);
	}
	_putchar(BUFF_OUT);
	va_end(arg);
	return (ind);
}
