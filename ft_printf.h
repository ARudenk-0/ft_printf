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
	char	hex_digits[16]; // 16 instead of 15 to hold "0123456789abcdef"
	char	buffer[20];     // Buffer to store reversed hex digits
	int		count;          // Character count
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
	int				precision;
	int				precision_specified;
}	t_format_info;

// Parse
int		ft_parse_precision(const char *format, int *i, t_format_info *info);

// New numeric formatting
int		ft_print_number_signed(long n, t_format_info *info);   // For %d, %i
int		ft_print_number_unsigned(unsigned long n, t_format_info *info, int base, int uppercase); // For %u, %x, %X

// Main
int		ft_printf(const char *format, ...);
int		parse_format(const char *format, int *i, t_format_info *info);
int		ft_print_arg(va_list args, t_format_info *info);
int		ft_check_width(const char *format, int *i);
int		ft_check_specifiers(const char *format, int *i, t_format_info *info);

// Specifiers
int		ft_print_pointer(void *ptr);
int		ft_print_hex_lowercase(unsigned long num, int fd);
int		ft_print_hex_uppercase(unsigned long num, int fd);

// Flags / width
int		ft_format_output(char *str, t_format_info *info);
int		ft_print_char_with_flags(char c, t_format_info *info);

// Char / string utils
int		ft_putnchar_fd_count(char c, int n, int fd);
int		ft_putstr_fd_count(char *s, int fd);
int		ft_putchar_fd_count(char c, int fd);

// Initialize
void	initialize_data(t_format_info *info);
void	initialize_data_hex_lowercase(t_hexad_format *format);
void	initialize_data_hex_uppercase(t_hexad_format *format);

// Numbers
int		ft_putnbr_fd_count(int n, int fd);
int		ft_putunbr_fd_count(unsigned int n, int fd);

// ltoa
char	*ft_ultoa_base(unsigned long n, int base, int uppercase);
int		ft_print_number_unsigned(unsigned long n, t_format_info *info, int base, int uppercase);

char	*ft_ltoa_no_sign(long n);
int		ft_print_number_signed(long n, t_format_info *info);

#endif