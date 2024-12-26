/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags_functions.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:56:44 by arudenko          #+#    #+#             */
/*   Updated: 2024/12/26 21:41:41 by arudenko         ###   ########.fr       */
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

	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	count = 0;
	effective_len = len;
	// printf("Before truncation:\nLen: %d; Effective len: %d\n", len, effective_len);
	effective_len = ft_truncate(info, effective_len);
	// printf("After truncation:\nLen: %d; Effective len: %d\n", len, effective_len);
	padding_char = ' ';
	if (info->f.zero == 1 && info->f.minus == 0 && info->precision_specified == 0)
		padding_char = '0';
	padding = 0;
	if (info->width > effective_len)
		padding = info->width - effective_len;
	if (info->f.minus == 0)
		count += ft_putnchar_fd_count(padding_char, padding, 1);
	count += ft_str(info, str, effective_len, padding);
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
