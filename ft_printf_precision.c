/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_precision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 21:38:49 by arudenko          #+#    #+#             */
/*   Updated: 2024/12/27 16:28:49 by arudenko         ###   ########.fr       */
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
		if (ft_isalpha(format[*i]))
			info->precision = 0;
		else if (ft_isdigit(format[*i]))
		{
			while (ft_isdigit(format[*i]))
			{
				value = value * 10 + (format[*i] - '0');
				(*i)++;
			}
			info->precision = value;
		}
	}
	return (0);
}
