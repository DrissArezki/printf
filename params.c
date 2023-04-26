#include "main.h"

/**
 * init_params - reset the buffer and clears params
 * @params: parameters structure
 * @arg: arguments
 *
 * Return: 0
 */

void init_params(params_t *params, va_list arg)
{
	params->plus_flag = 0;
	params->space_flag = 0;
	params->hashtag_flag = 0;
	params->h_modifier = 0;
	params->l_modifier = 0;
	params->width = 0;
	params->precision = UINT_MAX;
	params->zero_flag = 0;
	params->minus_flag = 0;
	params->unsign = 0;
	(void)arg;
}
