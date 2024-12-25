/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ltoa_signed.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 21:50:58 by arudenko          #+#    #+#             */
/*   Updated: 2024/12/26 00:12:14 by arudenko         ###   ########.fr       */
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
	ft_reverse(buffer, i);
	result = ft_strdup(buffer);
	return (result);
}

char	ft_reverse(char *buffer, int i)
{
	int		start;
	int		end;
	char	c;

	start = 0;
	end = i - 1;
	while (start < end)
	{
		c = buffer[start];
		buffer[start] = buffer[end];
		buffer[end] = c;
		start++;
		end--;
	}
	return (*buffer);
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
	final_str = NULL;
	if (n < 0)
	{
		is_neg = 1;
		n = -n;
	}
	num_part = ft_ltoa_no_sign(n);
	num_part = ft_null(info, num_part);
	len_num_part = ft_strlen(num_part);
	if (info->precision_specified == 1 && info->precision > len_num_part)
		num_part = ft_zero_pad(info, len_num_part, num_part);
	ft_signs(info, final_str, num_part, is_neg);
	free(num_part);
	// Now we have a fully built string with sign + leading zeros if needed.
	// Pass it to ft_format_output (which will handle width, '-' alignment, '0' if no precision, etc.)
	info->s.string = 1; // Trick to reuse ft_format_output as if it's a string
	count = ft_format_output(final_str, info);
	free(final_str);
	info->s.string = 0;
	return (count);
}

char	*ft_null(t_format_info *info, char *num_part)
{
	if (info->precision_specified == 1 && info->precision == 0
		&& num_part[0] == '0' && num_part[1] == '\0')
	{
		free(num_part);
		num_part = ft_strdup("");
	}
	return (num_part);
}

char	*ft_zero_pad(t_format_info *info, int len_num_part, char *num_part)
{
	int		needed_zeros;
	char	*zero_str;
	int		j;
	char	*old;

	needed_zeros = info->precision - len_num_part;
	zero_str = (char *)malloc(sizeof(char) * (needed_zeros + 1));
	j = 0;
	if (zero_str)
	{
		while (j < needed_zeros)
			zero_str[j++] = '0';
		zero_str[j] = '\0';
		{
			old = num_part;
			num_part = ft_strjoin(zero_str, num_part);
			free(old);
		}
		free(zero_str);
	}
	return (num_part);
}

char	*ft_signs(t_format_info *info, char *final_str, char *num_part, int is_neg)
{
	if (is_neg == 1)
		final_str = ft_strjoin("-", num_part);
	else if (info->f.plus == 1)
		final_str = ft_strjoin("+", num_part);
	else if (info->f.space == 1)
		final_str = ft_strjoin(" ", num_part);
	else
		final_str = ft_strdup(num_part);
	return(final_str);
}
