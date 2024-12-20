/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 22:19:43 by arudenko          #+#    #+#             */
/*   Updated: 2024/12/20 22:36:08 by arudenko         ###   ########.fr       */
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

void	initialize_data_hex_lowercase(t_hexad_format *format)
{
	(void)format;
	format->count = 0;
	ft_memcpy(format->hex_digits, "0123456789abcdef", 16);
}

void	initialize_data_hex_uppercase(t_hexad_format *format)
{
	(void)format;
	format->count = 0;
	ft_memcpy(format->hex_digits, "0123456789ABCDEF", 16);
}

int	ft_putnchar_fd(char c, int n, int fd)
{
	int	count;

	while (n > 0)
	{
		count += write(fd, &c, 1);
		n--;
	}
	return(count);
}

//TODO: ft_putstr_fd and ft_putnbr_fd?? make int return type
int	ft_putnubr_fd(int n, int fd)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		count += ft_putstr_fd("-2147483648", fd);
	else if (n < 0)
	{
		count += ft_putnchar_fd('-', 1, fd);
		n = -n;
		count += ft_putnbr_fd(n, fd);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + 48, fd);
	}
	else
		ft_putchar_fd(n + 48, fd);
	return (count);
}
// void	ft_add_prefix(char *result, char *prefix)
// {
	
// }
