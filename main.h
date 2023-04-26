#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>


#define BUFF_SIZE 1024
#define BUFF_OUT -1
#define NULL_STRING "(null)"
#define INIT_CONFIG {0, 0, 0, 0, 0, 0, 0, 0, 0, 0} /*struct params boolean*/
#define LOWERCASE 1
#define UNSIGNED 2

/**
 * struct params - structure of printf parameters
 * @plus_flag: +
 * @space_flag: " "
 * @hashtag_flag: #
 * @h_modifier : h or hh
 * @l_modifier : l
 * @width: field width
 * @precision: field precision
 * @zero_flag: "0"
 * @minus_flag: -
 * @unsign: flag if unsigned value
 */

typedef struct params
{
	unsigned int plus_flag : 1;
	unsigned int space_flag : 1;
	unsigned int hashtag_flag : 1;

	unsigned int h_modifier : 1;
	unsigned int l_modifier : 1;

	unsigned int width : 1;
	unsigned int precision : 1;

	unsigned int zero_flag : 1;

	unsigned int minus_flag : 1;

	unsigned int unsign : 1;
} params_t;

/**
 * struct spec - structure for every specifier
 * @spec: specifier or format
 * @func: the function of each specifier
 */

typedef struct spec
{
	char *spec;

	int (func *)(va_list, params_t *);

} spec_t;

/*main prototype*/
int _printf(const char *format, ...);
/*print functions*/
int _puts(char *str); /*takes whole string*/
int _putchar(int c);
int print_start_end(char *start, char *end, char *except);
/*task_0*/
int print_string(va_list arg, params_t *params);
int print_char(va_list arg, params_t *params);
int print_default(va_list arg, params_t *params);
/*task_1*/
int print_int(va_list arg, params_t *params);
/*task_2*/
int print_binary(va_list arg, params_t *params);
/*task_3*/
int print_uint(va_list arg, params_t *params);
int print_hex(va_list arg, params_t *params);
int print_HEX(va_list arg, params_t *params);
int print_oct(va_list arg, params_t *params);
/*task_5*/
int print_S(va_list arg, params_t *params);
/*task_6*/
int print_pointer(va_list arg, params_t *params);
/*task_13*/
int print_rev(va_list arg, params_t *params);
/*task_14*/
int print_rot13(va_list arg, params_t *params);
/*convert base func*/
char *convert(long int num, int base, int flags, params_t *params);
/*specifier functions*/
int (*get_spec(char *s))(va_list arg, params_t *params);
int print_func(char *s, va_list arg, params_t *params);
int get_flag(char *s, params_t *params);
int get_modifier(char *s, params_t *params);
char *get_width(char *s, va_list arg, params_t *params);
char *get_precision(char *p, params_t *params, va_list arg);
/*number print functions*/
int _isdigit(int c);
int _strlen(char *s);
int print_number(char *str, params_t *params);
int print_number_right(char *str, params_t *params);
int print_number_left(char *str, params_t *params);
/*initialization of params*/
void init_params(params_t *params, va_list arg);


#endif
