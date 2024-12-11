/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 20:53:04 by arudenko          #+#    #+#             */
/*   Updated: 2024/11/10 20:53:04 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct hexadF
{
	char	hex_digits[15]; // Hexadecimal characters
	char	buffer[16]; // Buffer to store the reversed hex number (max 16 for 64-bit)
	int		count;  // Character count
} hexadF;

typedef struct format_info
{
	flags		f;
	specifiers	s;
	int			width;
} format_info;

typedef struct flags
{
	//Any combo: -0. and the field minimum width
	//Manage all flags: # + (including space!!)

	int	minus;
	int	zero;
	int	hashtag;
	int	space;
	int	plus;
} flags;

typedef struct specifiers
{
	//cspdiuxX%
	int	character;
	int	string;
	int	pointer;
	int	decmal;
	int	integr;
	int	unsignedDes;
	int	unsigndLower;
	int	unsigndUpper;
	int	percentSign;

} specifiers;

int		ft_printf(const char *format, ...);
int		parse_format(const char *format, int *i, format_info *info);
void	initialize_data(format_info *info);
char	ft_print_text(va_list args, format_info *info);
int		ft_check_width(const char *format, int *i);
int		ft_check_specifiers(char *format, int *i, format_info *info);

//printf_spec_print
int	ft_print_pointer(va_list args);
int	ft_print_hexL(unsigned long num, int fd);
void	initialize_data_hexL(hexadF format);
void	initialize_data_hexU(hexadF format);

#endif