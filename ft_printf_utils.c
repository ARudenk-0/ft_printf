/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 22:19:43 by arudenko          #+#    #+#             */
/*   Updated: 2024/12/11 22:48:13 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initialize_data(format_info *info)
{
	specifiers	s;
	flags		f;

	s = (specifiers){0};
	f = (flags){0};
	info->s = s;
	info->f = f;
	info->width = 0;
}

void	initialize_data_hexL(hexadF format)
{
	format.hex_digits[15] = "0123456789abcdef";
	format.count = 0;
}

void	initialize_data_hexU(hexadF format)
{
	format.hex_digits[15] = "0123456789ABCDEF";
	format.count = 0;
}