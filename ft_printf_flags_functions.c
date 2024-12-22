/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags_functions.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:56:44 by arudenko          #+#    #+#             */
/*   Updated: 2024/12/22 17:07:32 by arudenko         ###   ########.fr       */
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
