/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags_functions.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:56:44 by arudenko          #+#    #+#             */
/*   Updated: 2024/12/27 13:11:27 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_output(char *str, t_format_info *info)
{
	int	len;
	int	padding_char;
	int	padding;
	int	count;
	int	effective_len;
	int	is_genuine_string;

	// 1) If no string, replace with "(null)" just for safety
	if (!str)
		str = "(null)";
	// 2) Calculate length and set default "effective_len"
	len = ft_strlen(str);
	effective_len = len;
	count = 0;
	// 3) Check if it's a genuine '%s' or not
	is_genuine_string = 0;
	if (info->s.string && !info->s.decmal && !info->s.integr
		&& !info->s.unsigned_des && !info->s.unsignd_lower
		&& !info->s.unsignd_upper && !info->s.pointer)
		is_genuine_string = 1;
	// 4) For genuine '%s', we apply precision as "max length to print"
	if (is_genuine_string && info->precision_specified)
	{
		if (info->precision < effective_len)
			effective_len = info->precision;  // truncate string
	}
	// 5) Decide on the padding character: '0' only if zero-flag is set,
	//    no left align, AND no precision was specified
	padding_char = ' ';
	if (info->f.zero == 1 && info->f.minus == 0 && info->precision_specified == 0)
		padding_char = '0';
	// 6) Compute how many padding chars are needed
	//    For genuine strings, we pad around "effective_len"
	//    For numeric/pointer, we pad around full length. However, we've already
	//    built final string (including signs, zeroes). So we do:
	if (is_genuine_string)
		padding = (info->width > effective_len) ? (info->width - effective_len) : 0;
	else
		padding = (info->width > len) ? (info->width - len) : 0;
	// 7) If right aligned (no '-'), print the padding first
	if (info->f.minus == 0)
		count += ft_putnchar_fd_count(padding_char, padding, 1);
	// 8) Print either "effective_len" characters (for %s) or entire 'str'
	if (is_genuine_string)
	{
		// Print substring up to effective_len
		count += write(1, str, effective_len);
	}
	else
	{
		// numeric or pointer => print the entire string
		count += ft_putstr_fd_count(str, 1);
	}
	// 9) If left aligned, print the padding after
	if (info->f.minus == 1)
		count += ft_putnchar_fd_count(' ', padding, 1);
	return (count);
}

int	ft_truncate(t_format_info *info, int effective_len)
{
	if (info->s.string == 1 && info->precision_specified == 1)
	{
		if (info->precision < effective_len)
			effective_len = info->precision;
	}
	return (effective_len);
}

int	ft_str(t_format_info *info, char *str, int effective_len, int padding)
{
	int	count;

	count = 0;
	if (info->s.string == 1 && info->precision_specified == 1) // Print the string (or substring)
		count += write(1, str, effective_len); // Print only up to effective_len
	else
		count += ft_putstr_fd_count(str, 1); // Print entire
	if (info->f.minus == 1) // If left-aligned ('-' flag), print the padding after
		count += ft_putnchar_fd_count(' ', padding, 1);
	return (count);
}

int	ft_print_char_with_flags(char c, t_format_info *info)
{
	int		count;
	int		padding;
	char	pad_char;

	count = 0;
	if (info->f.zero && !info->f.minus)
		pad_char = '0';
	else
		pad_char = ' ';
	if (info->width > 1)
		padding = info->width - 1;
	else
		padding = 0;
	if (!info->f.minus)
		count += ft_putnchar_fd_count(pad_char, padding, 1);
	count += write(1, &c, 1);
	if (info->f.minus)
		count += ft_putnchar_fd_count(' ', padding, 1);
	return (count);
}
