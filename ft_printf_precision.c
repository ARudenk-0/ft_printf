/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_precision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 21:38:49 by arudenko          #+#    #+#             */
/*   Updated: 2024/12/22 22:08:53 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_printf_precision.c */
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
		if (ft_isdigit(format[*i])) // if digits follow => parse them
		{
			while (ft_isdigit(format[*i]))
			{
				value = value * 10 + (format[*i] - '0');
				(*i)++;
			}
			info->precision = value;
		}
		else
			info->precision = 0; // e.g. "%.s" or "%. d", means precision = 0
	}
	return (0);
}
