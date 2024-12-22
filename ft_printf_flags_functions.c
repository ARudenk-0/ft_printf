/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags_functions.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:56:44 by arudenko          #+#    #+#             */
/*   Updated: 2024/12/22 21:44:12 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_printf_flags_functions.c */

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
	effective_len = len; // If it's a string and precision is specified, we may truncate
	if (info->s.string == 1 && info->precision_specified == 1)
	{
		if (info->precision < effective_len)
			effective_len = info->precision; // Truncate
	}
	padding_char = ' '; // Determine padding char
	if (info->f.zero == 1 && info->f.minus == 0 && info->precision_specified == 0)
		padding_char = '0'; // Use '0' only if no minus flag, no precision
	padding = 0; // Compute padding
	if (info->width > effective_len)
		padding = info->width - effective_len;
	if (info->f.minus == 0) // If right-aligned (no '-' flag), print the padding first
		count += ft_putnchar_fd_count(padding_char, padding, 1);
	if (info->s.string == 1 && info->precision_specified == 1) 	// Print the string (or substring)
		count += write(1, str, effective_len); // Print only up to effective_len
	else
		count += ft_putstr_fd_count(str, 1); // Print entire
	if (info->f.minus == 1) // If left-aligned ('-' flag), print the padding after
		count += ft_putnchar_fd_count(' ', padding, 1);
	return (count);
}

int	ft_print_char_with_flags(char c, t_format_info *info)
{
	int	count;
	int	padding;
	char pad_char;

	count = 0;
	/* We have to print exactly 1 char. If width > 1, we need width - 1 spaces (or zeroes). */
	if (info->f.zero && !info->f.minus)
		pad_char = '0';
	else
		pad_char = ' ';
	/* If width is 5, for example, we print 4 spaces/zeroes + 1 char. */
	padding = (info->width > 1) ? info->width - 1 : 0;
	/* If not left-aligned, print padding first */
	if (!info->f.minus)
		count += ft_putnchar_fd_count(pad_char, padding, 1);
	/* Print the single character (including '\0') */
	/* Use write(1, &c, 1) or ft_putchar_fd_count. They both write 1 byte. */
	count += write(1, &c, 1);
	/* If left-aligned, print padding after */
	if (info->f.minus)
		count += ft_putnchar_fd_count(' ', padding, 1);
	return (count);
}
