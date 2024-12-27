/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_spec_print.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 20:55:07 by arudenko          #+#    #+#             */
/*   Updated: 2024/12/27 17:25:04 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pointer(void *ptr, t_format_info *info)
{
	char			*str;
	int				count;
	unsigned long	addr;
	char			*hex;
	char			*tmp;

	if (!ptr)
	{
		str = ft_strdup("(nil)");
		if (!str)
			return (0);
	}
	else
	{
		addr = (unsigned long)ptr;
		hex = ft_ultoa_base(addr, 16, 0);
		tmp = ft_strjoin("0x", hex);
		free(hex);
		str = tmp;
	}
	info->s.string = 1;
	count = ft_format_output(str, info);
	info->s.string = 0;
	free(str);
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
