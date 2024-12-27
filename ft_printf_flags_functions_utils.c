/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags_functions_utils.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:58:03 by arudenko          #+#    #+#             */
/*   Updated: 2024/12/27 18:11:55 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_for_str(t_format_info *info)
{
	if (info->s.string && !info->s.decmal && !info->s.integr
		&& !info->s.unsigned_des && !info->s.unsignd_lower
		&& !info->s.unsignd_upper && !info->s.pointer)
		info->o.is_genuine_string = 1;
	if (info->o.is_genuine_string && info->precision_specified)
	{
		if (info->precision < info->o.effective_len)
			info->o.effective_len = info->precision;
	}
}

void	ft_count_padding(t_format_info *info)
{
	if (info->o.is_genuine_string)
	{
		if (info->width > info->o.effective_len)
			info->o.padding = (info->width - info->o.effective_len);
		else
			info->o.padding = 0;
	}
	else
	{
		if (info->width > info->o.len)
			info->o.padding = (info->width - info->o.len);
		else
			info->o.padding = 0;
	}
}
