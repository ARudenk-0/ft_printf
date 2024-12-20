/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags_functions.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:56:44 by arudenko          #+#    #+#             */
/*   Updated: 2024/12/20 21:57:36 by arudenko         ###   ########.fr       */
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
	count = len;
	if (info->f.zero && !info->f.minus) // Determine the padding character: '0' if zero flag is set and left-align is NOT set, otherwise ' '.
		padding_char = '0';
	else
		padding_char = ' ';
	if (info->width > len) // Calculate padding
		padding = info->width - len;
	else
		padding = 0;
	if (!info->f.minus) // Print padding (right-align if minus flag is NOT set)
		count += ft_putnchar_fd(padding_char, padding, 1);
	ft_putstr_fd(str, 1); // Print the string
	if (info->f.minus) // Print padding (left-align if minus flag IS set)
		count += ft_putnchar_fd(' ', padding, 1);
	return(count);
}

//TODO: separate printing in another function? ex: ft_print_everything?