/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ltoa_signed.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 21:50:58 by arudenko          #+#    #+#             */
/*   Updated: 2024/12/27 17:35:00 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_lltoa_no_sign(long long n)
{
	char	buffer[32];
	int		i;
	char	*result;

	i = 0;
	if (n == 0)
		return (ft_strdup("0"));
	while (n > 0 && i < 31)
	{
		buffer[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	buffer[i] = '\0';
	ft_reverse(buffer, i);
	result = ft_strdup(buffer);
	return (result);
}

char	*ft_apply_precision(char *digits, t_format_info *info)
{
	int		len;
	char	*tmp;
	int		needed;
	char	*zeros;

	len = ft_strlen(digits);
	if (info->precision_specified && info->precision == 0
		&& digits[0] == '0' && digits[1] == '\0')
	{
		free(digits);
		return (ft_strdup(""));
	}
	if (info->precision_specified && info->precision > len)
	{
		needed = info->precision - len;
		zeros = ft_make_zeros(needed);
		if (!zeros)
			return (digits);
		tmp = digits;
		digits = ft_strjoin(zeros, digits);
		free_two(tmp, zeros);
	}
	return (digits);
}

char	*ft_if_sign(char *final, int needed)
{
	t_sign	s;

	s.sign = final[0];
	s.digits = final + 1;
	s.zeros = ft_make_zeros(needed);
	if (!s.zeros)
		return (final);
	s.tmp = ft_strjoin(s.zeros, s.digits);
	free(s.zeros);
	s.new_str = (char *)malloc(ft_strlen(s.tmp) + 2);
	if (!s.new_str)
	{
		free(s.tmp);
		return (final);
	}
	s.new_str[0] = s.sign;
	s.len_tmp = ft_strlen(s.tmp);
	ft_strlcpy(s.new_str + 1, s.tmp, s.len_tmp + 1);
	free_two(s.tmp, final);
	return (s.new_str);
}

char	*ft_apply_zero_flag(char *final, t_format_info *info)
{
	int		len;
	int		needed;
	char	*zeros;
	char	*tmp;

	if (info->precision_specified || info->f.minus || !info->f.zero)
		return (final);
	len = ft_strlen(final);
	if (info->width <= len)
		return (final);
	needed = info->width - len;
	if (final[0] == '-' || final[0] == '+' || final[0] == ' ')
		return (ft_if_sign(final, needed));
	zeros = ft_make_zeros(needed);
	if (!zeros)
		return (final);
	tmp = ft_strjoin(zeros, final);
	free_two(zeros, final);
	return (tmp);
}

int	ft_print_number_signed(long long n, t_format_info *info)
{
	t_print_n	p;

	p.negative = 0;
	if (n < 0)
	{
		p.negative = 1;
		n = -n;
	}
	p.digits = ft_lltoa_no_sign(n);
	p.with_precision = ft_apply_precision(p.digits, info);
	p.with_sign = ft_add_sign(p.with_precision, info, p.negative);
	p.final_str = ft_apply_zero_flag(p.with_sign, info);
	info->s.string = 1;
	p.count = ft_format_output(p.final_str, info);
	info->s.string = 0;
	free(p.final_str);
	return (p.count);
}
