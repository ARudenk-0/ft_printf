/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_initializing.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:05:27 by arudenko          #+#    #+#             */
/*   Updated: 2024/12/21 20:06:00 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initialize_data(t_format_info *info)
{
	t_specifiers	s;
	t_flags			f;

	s = (t_specifiers){0};
	f = (t_flags){0};
	info->s = s;
	info->f = f;
	info->width = 0;
}

void	initialize_data_hex_lowercase(t_hexad_format *format)
{
	(void)format;
	format->count = 0;
	ft_memcpy(format->hex_digits, "0123456789abcdef", 16);
}

void	initialize_data_hex_uppercase(t_hexad_format *format)
{
	(void)format;
	format->count = 0;
	ft_memcpy(format->hex_digits, "0123456789ABCDEF", 16);
}
