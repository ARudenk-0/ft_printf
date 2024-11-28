/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 20:52:32 by arudenko          #+#    #+#             */
/*   Updated: 2024/11/10 20:52:32 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_print_text(char *string, va_list args)
{

}

int ft_check_specifiers(char *format, int i)
{
	specifiers	s;

	while(format[i])
	{
		i++;
		if(format[i] == 'c')
			s.character == 1;
		else if(format[i] == 's')
			s.string == 1;
		else if(format[i] == 'p')
			s.pointer == 1;
		else if(format[i] == 'd')
			s.decmal == 1;
		else if(format[i] == 'i')
			s.integr == 1;
		else if(format[i] == 'u')
			s.unsignedDes == 1;
		else if(format[i] == 'x')
			s.unsigndLower == 1;
		else if(format[i] == 'X')
			s.unsigndUpper == 1;
		else if(format[i] == '%')
			s.percentSign == 1;
	}
	return (i);
}

int	ft_check_flags(char *format, int i)
{
	flags	flags;

	while(format[i])
	{
		i++;
		if(format[i] == '-')
			flags.minus == 1;
		else if(format[i] == '0')
			flags.zero == 1;
		else if(format[i] == '.')
			flags.dot == 1;
		//TODO: field minimum width
		else if(format[i] == '#')
			flags.hashtag == 1;
		else if(format[i] == ' ')
			flags.space == 1;
		else if(format[i] == '+')
			flags.plus == 1;
	}
	return(i);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	char	*copy;
	int		i;

	i = 0;
	if(!format || *format == '\0')
		return (0);
	copy = ft_strdup(format);
	if(!copy || *copy == '\0')
		return (0);
	va_start(args, format);
	while (copy[i])
	{
		if (copy[i] == '%' && copy[i] != '/0')
		{
			ft_check_flags(copy[i], i);
			ft_check_specifiers(copy[i], i);
			ft_print_text(copy, args);
		}
		else if(copy[i])
			ft_print_text(copy, args);
		i++;
	}
	va_end(args);
	return(i);
}