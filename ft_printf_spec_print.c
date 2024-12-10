/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_spec_print.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 20:55:07 by arudenko          #+#    #+#             */
/*   Updated: 2024/12/10 10:49:55 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_pointer(va_list args)
{
	unsigned long int address; // Store the address
	int count = 0;             // Track characters printed

	void *ptr = va_arg(args, void *); // Extract the next argument as a pointer
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
	return(num);
}

int	ft_print_hexL(va_list args)
{
	return(num);
}

int	ft_print_hexU(va_list args)
{
	return(num);
}