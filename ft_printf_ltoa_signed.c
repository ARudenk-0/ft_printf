/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ltoa_signed.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 21:50:58 by arudenko          #+#    #+#             */
/*   Updated: 2024/12/26 23:27:21 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_number_signed(long n, t_format_info *info)
{
	int		count;
	char	*num_part;
	char	*final_str;
	int		len_num_part;
	long	tmp;

	count = 0;
	final_str = NULL;
	printf("Argument is: %ld\n", n);
	if (n < 0)
		tmp = ft_neg(n, info);
	else
		tmp = n;
	printf("Argument after becoming positive(tmp): %ld\n", tmp);
	printf("Argument itself(n): %ld\n", n);
	num_part = ft_ltoa_no_sign(tmp);
	printf("The string is: %s\n", num_part);
	num_part = ft_null(info, num_part);
	len_num_part = ft_strlen(num_part);
	if ((info->precision_specified == 1 || info->width > 0)
			&& info->precision > len_num_part)
		{
			num_part = ft_zero_pad(info, len_num_part, num_part);
			printf("Padded string: %s\n", num_part);
		}
	final_str = ft_signs(info, final_str, num_part);
	printf("And the final string (after '+- ' signs checked) is: %s\n", final_str);
	info->s.string = 1;
	count = ft_format_output(final_str, info);
	free_two(num_part, final_str);
	info->s.string = 0;
	return (count);
}

char	*ft_ltoa_no_sign(long n)
{
	char	buffer[32];
	char	*result;
	int		i;
	long	tmp;
	char	*to_reverse;

	printf("Ltoa in action\n");
	if (n == 0)
		return (ft_strdup("0"));
	i = 0;
	tmp = n;
	printf("Value of tmp: %ld\n", tmp);
	while (tmp > 0)
	{
		printf("Printing the reversed buffer %d\n", i);
		printf("Buffer at position %d: %d\n", i, buffer[i]);
		buffer[i] = (tmp % 10) + '0';
		tmp = tmp / 10;
		i++;
	}
	buffer[i] = '\0';
	to_reverse = ft_reverse(buffer, i);
	result = ft_strdup(to_reverse);
	return (result);
}

char	*ft_signs(t_format_info *info, char *fin_str, char *n_part)
{
	if (info->is_neg == 1)
		fin_str = ft_strjoin("-", n_part);
	else if (info->f.plus == 1)
		fin_str = ft_strjoin("+", n_part);
	else if (info->f.space == 1)
		fin_str = ft_strjoin(" ", n_part);
	else
		fin_str = ft_strdup(n_part);
	return (fin_str);
}

long	ft_neg(long n, t_format_info *info)
{
	info->is_neg = 1;
	n = -n;
	return (n);
}
