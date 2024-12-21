/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags_functions.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:56:44 by arudenko          #+#    #+#             */
/*   Updated: 2024/12/21 21:56:37 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_output(char *str, t_format_info *info)
{
	int	len;
	int	padding_char;
	int	padding;
	int	count;

	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	count = 0;

	// Determine padding char
	if (info->f.zero && !info->f.minus)
		padding_char = '0';
	else
		padding_char = ' ';

	// Compute padding
	if (info->width > len)
		padding = info->width - len;
	else
		padding = 0;

	// If right-aligned (no '-' flag), print the padding first
	if (!info->f.minus)
		count += ft_putnchar_fd_count(padding_char, padding, 1);

	// Then print the string itself
	count += ft_putstr_fd_count(str, 1);

	// If left-aligned ('-' flag), print the padding after
	if (info->f.minus)
		count += ft_putnchar_fd_count(' ', padding, 1);

	return (count);
}