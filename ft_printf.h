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

# include <libft/libft.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct flags 
{
	//Any combo: -0. and the field minimum width
	//Manage all flags: # + (including space!!)

	int	minus;
	int	zero;
	int	dot;
	//TODO: field minimun width!
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

int	ft_printf(const char *format, ...);
int	ft_check_flags(char *format, int i);
int	ft_check_specifiers(char *format, int i, specifiers s);
char	ft_print_text(va_list args, specifiers s);

#endif