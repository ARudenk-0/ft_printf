/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:56:44 by arudenko          #+#    #+#             */
/*   Updated: 2024/12/13 18:43:51 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format_string(char *str, t_format_info *info)
{
	int	len;
	int	padding;

	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (info->width > len)
		padding = info->width - len;
	else
		padding = 0;
	if (!info->f.minus) // Right-aligned padding
		ft_putnchar_fd(' ', padding, 1);
	ft_putstr_fd(str, 1);
	if (info->f.minus) // Left-aligned padding
		ft_putnchar_fd(' ', padding, 1);
}
