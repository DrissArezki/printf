#include "main.h"

/**
 * _puts - prints a string
 * @str: string to print
 * Return: string
 */

int _puts(char *str)
{
	char *s = str;

	while (*str)
		_putchar(*str++);
	return (str - s);
}
