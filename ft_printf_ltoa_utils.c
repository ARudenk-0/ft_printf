/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ltoa_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:41:24 by arudenko          #+#    #+#             */
/*   Updated: 2024/12/26 22:35:44 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_reverse(char *buffer, int i)
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
	return (buffer);
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
		old = num_part;
		num_part = ft_strjoin(zero_str, num_part);
		free(old);
		free(zero_str);
	}
	else if (!zero_str)
		free(zero_str);
	return (num_part);
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

void	free_two(char *s1, char *s2)
{
	free(s1);
	free(s2);
}
