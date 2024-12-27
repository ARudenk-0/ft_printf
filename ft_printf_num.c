/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:06:02 by arudenko          #+#    #+#             */
/*   Updated: 2024/12/27 16:28:58 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd_count(int n, int fd)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (ft_putstr_fd_count("-2147483648", fd));
	if (n < 0)
	{
		count += ft_putchar_fd_count('-', fd);
		count += ft_putnbr_fd_count(-n, fd);
	}
	else if (n >= 10)
	{
		count += ft_putnbr_fd_count(n / 10, fd);
		count += ft_putchar_fd_count((n % 10) + '0', fd);
	}
	else
		count += ft_putchar_fd_count(n + '0', fd);
	return (count);
}

int	ft_putunbr_fd_count(unsigned int n, int fd)
{
	int	count;

	count = 0;
	if (n >= 10)
	{
		count += ft_putunbr_fd_count(n / 10, fd);
		count += ft_putchar_fd_count((n % 10) + '0', fd);
	}
	else
		count += ft_putchar_fd_count(n + '0', fd);
	return (count);
}
