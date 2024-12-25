/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 09:05:43 by arudenko          #+#    #+#             */
/*   Updated: 2024/12/25 20:44:03 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_arg_csp(va_list args, t_format_info *info, int count)
{
	char	ch;
	char	tmp[2];
	char	*str;
	void	*ptr;

	if (info->s.character)
	{
		ch = (char)va_arg(args, int);
		tmp[0] = ch;
		tmp[1] = '\0';
		count += ft_print_char_with_flags(tmp[0], info);
	}
	else if (info->s.string)
	{
		str = va_arg(args, char *);
		count += ft_format_output(str, info);
	}
	else if (info->s.pointer)
	{
		ptr = va_arg(args, void *);
		count += ft_print_pointer(ptr);
	}
	return (count);
}

int	ft_print_arg_unsigned(va_list args, t_format_info *info, int count)
{
	unsigned long	n;

	if (info->s.unsignd_lower)
	{
		n = (unsigned long)va_arg(args, unsigned int);
		count += ft_print_num_unsgnd(n, info, 16, 0);
	}
	else if (info->s.unsignd_upper)
	{
		n = (unsigned long)va_arg(args, unsigned int);
		count += ft_print_num_unsgnd(n, info, 16, 1);
	}
	return (count);
}
