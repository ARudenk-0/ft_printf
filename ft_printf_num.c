/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:06:02 by arudenko          #+#    #+#             */
/*   Updated: 2024/12/21 20:12:03 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd_count(char *s, int fd)
{
	int	count;

	count = 0;
	while (*s)
		count += ft_putchar_fd(*s++, fd);
	return (count);
}

int	ft_putnbr_fd_count(int n, int fd)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		count += ft_putstr_fd_count("-2147483648", fd);
	else if (n < 0)
	{
		count += ft_putchar_fd('-', fd);
		count += ft_putnbr_fd_count(-n, fd);
	}
	else if (n >= 10)
	{
		count += ft_putnbr_fd_count(n / 10, fd);
		count += ft_putchar_fd((n % 10) + '0', fd);
	}
	else
		count += ft_putchar_fd(n + '0', fd);
	return (count);
}
