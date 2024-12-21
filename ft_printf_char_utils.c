/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 22:19:43 by arudenko          #+#    #+#             */
/*   Updated: 2024/12/21 21:57:03 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd_count(char c, int fd)
{
	return (write(fd, &c, 1));
}

int	ft_putnchar_fd_count(char c, int n, int fd)
{
	int	count;

	count = 0;
	while (n > 0)
	{
		count += write(fd, &c, 1);
		n--;
	}
	return (count);
}

int	ft_putstr_fd_count(char *s, int fd)
{
	int	count;

	count = 0;
	if (!s)
		return (0); // or print "(null)" or handle as you wish
	while (*s)
	{
		count += ft_putchar_fd_count(*s, fd);
		s++;
	}
	return (count);
}
