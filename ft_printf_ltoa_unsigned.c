/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ltoa_unsigned.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 21:54:55 by arudenko          #+#    #+#             */
/*   Updated: 2024/12/22 22:12:47 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
** Convert an unsigned long 'n' to an allocated string in 'base'.
** If uppercase == 0 => use "0123456789abcdef"
** If uppercase == 1 => use "0123456789ABCDEF"
*/
//TODO: Find a libft function or C piscine function that does the reversing of the buffer
// Check if you can exchange if(uppercase...) lines with hex initializing functions that you already have
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
	{
		int start = 0; 	// Reverse buffer
		int end = i - 1;
		char c;
		while (start < end)
		{
			c = buffer[start];
			buffer[start] = buffer[end];
			buffer[end] = c;
			start++;
			end--;
		}
	}
	result = ft_strdup(buffer);
	return (result);
}

//TODO: break down into 3 smaller functions
int	ft_print_number_unsigned(unsigned long n, t_format_info *info, int base, int uppercase)
{
	int		count;
	char	*num_part;
	char	*final_str;
	int		len_num_part;
	int		is_zero;

	is_zero = 0;
	count = 0;
	// 1) Convert to string
	num_part = ft_ultoa_base(n, base, uppercase);
	// Check if "0"
	if (num_part[0] == '0' && num_part[1] == '\0')
		is_zero = 1;
	// 2) If precision=0 and the number is 0 => print nothing
	if (info->precision_specified == 1 && info->precision == 0 && is_zero == 1)
	{
		free(num_part);
		num_part = ft_strdup("");
	}
	// 3) Apply precision => leading zeros up to 'info->precision'
	len_num_part = ft_strlen(num_part);
	if (info->precision_specified == 1 && info->precision > len_num_part)
	{
		int needed_zeros;
		char *zero_str;
		char *old;
		int j;

		needed_zeros = info->precision - len_num_part;
		zero_str = (char *)malloc(sizeof(char) * (needed_zeros + 1));
		if (zero_str)
		{
			j = 0;
			while (j < needed_zeros)
			{
				zero_str[j] = '0';
				j++;
			}
			zero_str[j] = '\0';
			old = num_part;
			num_part = ft_strjoin(zero_str, num_part);
			free(old);
			free(zero_str);
		}
	}
	// 4) If '#' flag for hex and not zero => prepend "0x" or "0X"
	final_str = NULL;
	if (info->f.hashtag == 1 && base == 16 && is_zero == 0)
	{
		if (uppercase == 1)
			final_str = ft_strjoin("0X", num_part);
		else
			final_str = ft_strjoin("0x", num_part);
	}
	else
	{
		final_str = ft_strdup(num_part);
	}
	free(num_part);
	// 5) Use ft_format_output
	info->s.string = 1;
	count = ft_format_output(final_str, info);
	free(final_str);
	info->s.string = 0;
	return (count);
}
