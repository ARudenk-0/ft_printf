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

typedef struct s_hexad_format
{
	char	hex_digits[15];// Hexadecimal characters
	char	buffer[20];// Buffer to store the reversed hex number (max 16 for 64-bit)
	int		count;// Character count
}	t_hexad_format;

typedef struct s_flags
{
	int	minus;
	int	zero;
	int	hashtag;
	int	space;
	int	plus;
}	t_flags;

typedef struct s_specifiers
{
	int	character;
	int	string;
	int	pointer;
	int	decmal;
	int	integr;
	int	unsigned_des;
	int	unsignd_lower;
	int	unsignd_upper;
	int	percent_sign;
}	t_specifiers;

typedef struct s_format_info
{
	t_flags			f;
	t_specifiers	s;
	int				width;
}	t_format_info;

int		ft_printf(const char *format, ...);
int		parse_format(const char *format, int *i, t_format_info *info);
int		ft_print_arg(va_list args, t_format_info *info);
int		ft_check_width(const char *format, int *i);
int		ft_check_specifiers(const char *format, int *i, t_format_info *info);

//ft_printf_spec_print
int		ft_print_pointer(va_list args);
int		ft_print_hex_lowercase(unsigned long num, int fd);
int		ft_print_hex_uppercase(unsigned long num, int fd);

// ft_printf_flags_functions
int		ft_format_output(char *str, t_format_info *info);

//ft_printf_utils
void	initialize_data(t_format_info *info);
void	initialize_data_hex_lowercase(t_hexad_format *format);
void	initialize_data_hex_uppercase(t_hexad_format *format);
int		ft_putnchar_fd(char c, int n, int fd);
int		ft_putnubr_fd(int n, int fd);


#endif