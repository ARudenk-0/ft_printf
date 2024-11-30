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

char	ft_print_text(va_list args, specifiers s)
{
	int count;

	//TODO: На данном этапе Count не будет ноль уже, надо доработать!
	if(s.character)
		ft_putchar_fd(va_arg(args, char), 1);
	else if(s.string)
		ft_putstr_fd(va_arg(args, const char *), 1);
	else if(s.pointer)
		ft_print_pointer((unsigned long int)va_arg(args, void *));
	else if(s.decmal || s.integr)
		ft_putnbr_fd(va_arg(args, int), 1);
	else if(s.unsignedDes)
		ft_putdec_nbr(va_arg(args, unsigned int), 1);
	else if(s.unsigndLower)
		ft_print_hexL(va_arg(args, unsigned int), 1);
	else if(s.unsigndUpper)
		ft_print_hexU(va_arg(args, unsigned int), 1);
	else if(s.percentSign)
		ft_putchar_fd('%', 1);
	return(count);
}

int	ft_check_width(char *format, int i)
{
	int	width;

	width = 0;
	i++;
	while(format[i] && format[i+1] != '.')
	{
		if(format[i] != '0' && (format[i] >= 48 && format[i] <= 57))
		{
			width = (width * 10) + (format[i] - '0');
			i++;
		}
		else if(format[i] == '0')
			width = (width * 10) + (format[i] - '0');
	}
	width = (width * 10) + (format[i] - '0');
	return(i);
}

int	ft_check_specifiers(char *format, int i, specifiers s)
{
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
		else if(format[i] == '#')
			flags.hashtag == 1;
		else if(format[i] == ' ')
			flags.space == 1;
		else if(format[i] == '+')
			flags.plus == 1;
		else
			return(i);
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	specifiers	s;
	char	*copy;
	int		i;
	int		charnumber;

	i = 0;
	charnumber = 0;
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
			//TODO: count or i - how are they handled throught the code?
			ft_check_flags(copy[i], i);
			ft_check_width(copy[i], i);
			ft_check_specifiers(copy[i], i, s);
			charnumber += ft_print_text(args, s);
		}
		else
			//TODO: use different function to print arg0+format instead of ft_putstr_fd. And tbh you need to use putchar...
			charnumber += ft_putstr_fd(copy, 1);
		charnumber++;
		i++;
	}
	va_end(args);
	return(charnumber);
}

int	main()
{
	ft_printf("Text here %d\n", 46, 79, -234);
	return(0);
}