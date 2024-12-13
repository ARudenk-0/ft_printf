/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 22:19:43 by arudenko          #+#    #+#             */
/*   Updated: 2024/12/13 18:58:50 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initialize_data(t_format_info *info)
{
	t_specifiers	s;
	t_flags			f;

	s = (t_specifiers){0};
	f = (t_flags){0};
	info->s = s;
	info->f = f;
	info->width = 0;
}

void	initialize_data_hex_lowercase(t_hexad_format format)
{
	format.hex_digits[15] = "0123456789abcdef";
	format.count = 0;
}

void	initialize_data_hex_uppercase(t_hexad_format format)
{
	format.hex_digits[15] = "0123456789ABCDEF";
	format.count = 0;
}

void	ft_putnchar_fd(char c, int n, int fd)
{
	while (n > 0)
	{
		write(fd, &c, 1);
		n--;
	}
}

void	ft_add_prefix(char *result, char *prefix)
{
	
}