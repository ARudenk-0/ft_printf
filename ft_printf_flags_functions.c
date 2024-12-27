/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags_functions.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:56:44 by arudenko          #+#    #+#             */
/*   Updated: 2024/12/27 18:12:56 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_output(char *str, t_format_info *info)
{
	int	count;

	if (!str)
		str = "(null)";
	info->o.len = ft_strlen(str);
	info->o.effective_len = info->o.len;
	count = 0;
	info->o.is_genuine_string = 0;
	ft_check_for_str(info);
	info->o.padding_char = ' ';
	if (info->f.zero == 1 && info->f.minus == 0
		&& info->precision_specified == 0)
		info->o.padding_char = '0';
	ft_count_padding(info);
	if (info->f.minus == 0)
		count += ft_putnchar_fd_count(info->o.padding_char, info->o.padding, 1);
	if (info->o.is_genuine_string)
		count += write(1, str, info->o.effective_len);
	else
		count += ft_putstr_fd_count(str, 1);
	if (info->f.minus == 1)
		count += ft_putnchar_fd_count(' ', info->o.padding, 1);
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
	if (info->s.string == 1 && info->precision_specified == 1)
		count += write(1, str, effective_len);
	else
		count += ft_putstr_fd_count(str, 1);
	if (info->f.minus == 1)
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
