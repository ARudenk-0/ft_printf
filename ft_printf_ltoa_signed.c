/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ltoa_signed.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 21:50:58 by arudenko          #+#    #+#             */
/*   Updated: 2024/12/22 22:14:04 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Convert a long 'n' to an allocated decimal string without sign.
** This is basically like a custom itoa, ignoring negativity.
** If n == 0 => returns "0".
*/
//TODO: Find a libft function or C piscine function that does the reversing of the buffer
// Check if you can exchange if(uppercase...) lines with hex initializing functions that you already have
char	*ft_ltoa_no_sign(long n)
{
	char	buffer[32];
	int		i;
	char	*result;
	long	tmp;

	if (n == 0)
		return (ft_strdup("0"));
	i = 0;
	tmp = n;
	while (tmp > 0)
	{
		buffer[i] = (tmp % 10) + '0';
		tmp = tmp / 10;
		i++;
	}
	buffer[i] = '\0';
	// Reverse the buffer
	{
		int start = 0;
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

/*
** Build the final numeric string for %d / %i with flags: +, space, precision, etc.
** Then pass it to ft_format_output().
** n can be negative or positive.
*/

//TODO: break down into 3 smaller functions
int	ft_print_number_signed(long n, t_format_info *info)
{
	int		count;
	int		is_neg;
	char	*num_part;
	char	*final_str;
	int		len_num_part;

	count = 0;
	is_neg = 0;
	if (n < 0)
	{
		is_neg = 1;
		n = -n;
	}
	// Convert absolute value to decimal string
	num_part = ft_ltoa_no_sign(n);
	// If user wrote "%.0d" or similar and n=0 => print nothing for the digits
	if (info->precision_specified == 1 && info->precision == 0 && num_part[0] == '0' && num_part[1] == '\0')
	{
		free(num_part);
		num_part = ft_strdup("");
	}
	// Now apply precision => we may need leading zeros
	len_num_part = ft_strlen(num_part);
	if (info->precision_specified == 1 && info->precision > len_num_part)
	{
		int needed_zeros = info->precision - len_num_part;
		char *zero_str = (char *)malloc(sizeof(char) * (needed_zeros + 1));
		int j = 0;
		if (zero_str)
		{
			while (j < needed_zeros)
			{
				zero_str[j] = '0';
				j++;
			}
			zero_str[j] = '\0';
			// Combine zero_str + num_part
			{
				char *old = num_part;
				num_part = ft_strjoin(zero_str, num_part);
				free(old);
			}
			free(zero_str);
		}
	}
	// Now handle sign / space / plus
	final_str = NULL;
	if (is_neg == 1)
		final_str = ft_strjoin("-", num_part);
	else if (info->f.plus == 1)
		final_str = ft_strjoin("+", num_part);
	else if (info->f.space == 1)
		final_str = ft_strjoin(" ", num_part);
	else
	{
		// no sign
		final_str = ft_strdup(num_part);
	}
	free(num_part);
	// Now we have a fully built string with sign + leading zeros if needed.
	// Pass it to ft_format_output (which will handle width, '-' alignment, '0' if no precision, etc.)
	info->s.string = 1; // Trick to reuse ft_format_output as if it's a string
	count = ft_format_output(final_str, info);
	free(final_str);
	info->s.string = 0;
	return (count);
}
