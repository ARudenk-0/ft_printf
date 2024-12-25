/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_precision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 21:38:49 by arudenko          #+#    #+#             */
/*   Updated: 2024/12/25 20:47:09 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_precision(const char *format, int *i, t_format_info *info)
{
	int	value;

	value = 0;
	info->precision_specified = 0;
	info->precision = 0;
	if (format[*i] == '.')
	{
		info->precision_specified = 1;
		(*i)++;
		if (ft_isdigit(format[*i]))
		{
			while (ft_isdigit(format[*i]))
			{
				value = value * 10 + (format[*i] - '0');
				(*i)++;
			}
			info->precision = value;
		}
		else
			info->precision = 0;
	}
	return (0);
}

//else {info->precision = 0;} // e.g. "%.s" or "%. d", means precision = 0