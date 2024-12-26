/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ltoa_unsigned.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 21:54:55 by arudenko          #+#    #+#             */
/*   Updated: 2024/12/26 16:05:25 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
** Convert an unsigned long 'n' to an allocated string in 'base'.
** If uppercase == 0 => use "0123456789abcdef"
** If uppercase == 1 => use "0123456789ABCDEF"
*/
char	*ft_ultoa_base(unsigned long n, int base, int uppercase)
{
	char			buffer[64];
	unsigned long	tmp;
	int				i;
	char			*digits;
	char			*result;

	i = 0;
	tmp = n;
	if (uppercase == 1)
		digits = "0123456789ABCDEF";
	else
		digits = "0123456789abcdef";
	if (n == 0)
		return (ft_strdup("0"));
	while (tmp > 0)
	{
		buffer[i] = digits[tmp % base];
		tmp = tmp / base;
		i++;
	}
	buffer[i] = '\0';
	ft_reverse(buffer, i);
	result = ft_strdup(buffer);
	return (result);
}

int	ft_print_num_unsgnd(unsigned long n,
			t_format_info *info, int base, int uppercase)
{
	int		count;
	char	*num_part;
	char	*final_str;
	int		len_num_part;
	int		is_zero;

	is_zero = 0;
	count = 0;
	final_str = NULL;
	num_part = ft_ultoa_base(n, base, uppercase);
	if (num_part[0] == '0' && num_part[1] == '\0')
		is_zero = 1;
	ft_null(info, num_part);
	len_num_part = ft_strlen(num_part);
	if (info->precision_specified == 1 && info->precision > len_num_part)
		num_part = ft_zero_pad(info, len_num_part, num_part);
	if (info->f.hashtag == 1 && base == 16 && is_zero == 0)
		final_str = ft_prepend(uppercase, final_str, num_part);
	else
		final_str = ft_strdup(num_part);
	info->s.string = 1;
	count = ft_format_output(final_str, info);
	free_two(num_part, final_str);
	info->s.string = 0;
	return (count);
}

char	*ft_prepend(int upcase, char *fin_str, char *num_part)
{
	if (upcase == 1)
		fin_str = ft_strjoin("0X", num_part);
	else
		fin_str = ft_strjoin("0x", num_part);
	return (fin_str);
}
