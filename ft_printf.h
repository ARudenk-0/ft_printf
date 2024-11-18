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
	//cspdiuxX%
	//Any combo: -0. and the field minimum width
	//Manage all flags: # + (including space!!)

	char			character;
	char			*string;
	void			*pointer;
	int				decimal;
	int				integr;
	unsigned int	unsigndLower;
	unsigned int	unsigndUpper;
	int				percentSign;

	decimal = 0;
	integr = 0;
	unsigndLower = 0;
	unsigndUpper = 0;
	percentSign = 0;

} flags;

int	ft_printf(const char *format, ...);

#endif