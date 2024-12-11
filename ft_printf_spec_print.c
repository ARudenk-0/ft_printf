/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_spec_print.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 20:55:07 by arudenko          #+#    #+#             */
/*   Updated: 2024/12/11 23:20:05 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pointer(va_list args)
{
	int					count; // Track characters printed
	void				*ptr;
	unsigned long int	address; // Store the address
	count = 0;
	ptr = va_arg(args, void *); // Extract the next argument as a pointer
	if (!ptr)
	{
		ft_putstr_fd("(nil)", 1);
		return (5); // (nil) is 5 characters
	}
	address = (unsigned long int)ptr; // Convert the pointer to an unsigned long and print as hex
	ft_putstr_fd("0x", 1); // Print "0x" prefix
	count += 2; // '0x' prefix
	count += ft_print_hexL(address, 1); // Print address in hex
	return (count);
}

int	ft_putdec_nbr(va_list args)
{
	return (num);
}

int	ft_print_hex_lowercase(unsigned long num, int fd)
{
	hexad_format	format;
	int				i;

	i = 0;
	initialize_data_hexL(format);
	if (num == 0) // Handle the case for 0 explicitly
	{
		ft_putchar_fd('0', fd);
		return (1); // Only 1 character printed
	}
	while (num > 0) // Convert the number to hexadecimal (store digits in reverse)
	{
		format.buffer[i++] = format.hex_digits[num % 16];
		num /= 16;
	}
	while (i-- > 0) // Print the digits in reverse order
	{
		ft_putchar_fd(format.buffer[i], fd);
		format.count++;
	}
	return (format.count); // Return the total number of characters printed
}

int	ft_print_hex_uppercase(unsigned long num, int fd)
{
	hexad_format	format;
	int				i;

	i = 0;
	initialize_data_hexU(format);
	if (num == 0)
	{
		ft_putchar_fd('0', fd);
		return (1);
	}
	while (num > 0)
	{
		format.buffer[i++] = format.hex_digits[num % 16];
		num /= 16;
	}
	while (i-- > 0)
	{
		ft_putchar_fd(format.buffer[i], fd);
		format.count++;
	}
	return (format.count);
}
