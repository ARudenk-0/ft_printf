/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_spec_print.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 20:55:07 by arudenko          #+#    #+#             */
/*   Updated: 2024/12/21 21:55:40 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pointer(void *ptr)
{
	int					count;
	unsigned long		address;

	count = 0;
	if (!ptr)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	address = (unsigned long)ptr; 
	count += ft_putstr_fd_count("0x", 1);
	count += ft_print_hex_lowercase(address, 1);
	return (count);
}

int	ft_print_hex_lowercase(unsigned long num, int fd)
{
	t_hexad_format	format;
	int				i;

	i = 0;
	initialize_data_hex_lowercase(&format);
	if (num == 0)
		return (ft_putchar_fd_count('0', fd));
	while (num > 0)
	{
		format.buffer[i++] = format.hex_digits[num % 16];
		num /= 16;
	}
	while (i-- > 0)
	{
		ft_putchar_fd_count(format.buffer[i], fd);
		format.count++;
	}
	return (format.count);
}

int	ft_print_hex_uppercase(unsigned long num, int fd)
{
	t_hexad_format	format;
	int				i;

	i = 0;
	initialize_data_hex_uppercase(&format);
	if (num == 0)
		return (ft_putchar_fd_count('0', fd));
	while (num > 0)
	{
		format.buffer[i++] = format.hex_digits[num % 16];
		num /= 16;
	}
	while (i-- > 0)
	{
		ft_putchar_fd_count(format.buffer[i], fd);
		format.count++;
	}
	return (format.count);
}
