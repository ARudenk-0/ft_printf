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

char	ft_print_text(va_list args, specifiers s, flags f, int width)
{
	int count = 0;

	//TODO: На данном этапе Count не будет ноль уже, надо доработать!
	if(s.character)
		ft_putchar_fd(va_arg(args, int), 1); //had to change va_args(args, char) to ~(, int)
	else if(s.string)
	{
		if(!va_arg(args, char *))
			ft_putstr_fd("(null)", 1);
		else
			ft_putstr_fd(va_arg(args, char *), 1);
	}
	else if(s.pointer)
		ft_print_pointer((unsigned long int)va_arg(args, void *)); //TODO
	else if(s.decmal || s.integr)
		ft_putnbr_fd(va_arg(args, int), 1);
	else if(s.unsignedDes)
		ft_putdec_nbr(va_arg(args, unsigned int), 1); //TODO
	else if(s.unsigndLower)
		ft_print_hexL(va_arg(args, unsigned int), 1); //TODO
	else if(s.unsigndUpper)
		ft_print_hexU(va_arg(args, unsigned int), 1); //TODO
	else if(s.percentSign)
		ft_putchar_fd('%', 1);
	return(count);
}

int	ft_check_width(const char *format, int *i)
{
	int	width = 0;

	while (format[*i] && ft_isdigit(format[*i]))
	{
		width = (width * 10) + (format[*i] - '0');
		(*i)++;
	}
	return (width);
}

int	ft_check_specifiers(char *format, int *i, specifiers *s)
{
	while(format[*i])
	{
		(*i)++;
		if(format[*i] == 'c')
			s->character = 1;
		else if(format[*i] == 's')
			s->string = 1;
		else if(format[*i] == 'p')
			s->pointer = 1;
		else if(format[*i] == 'd')
			s->decmal = 1;
		else if(format[*i] == 'i')
			s->integr = 1;
		else if(format[*i] == 'u')
			s->unsignedDes = 1;
		else if(format[*i] == 'x')
			s->unsigndLower = 1;
		else if(format[*i] == 'X')
			s->unsigndUpper = 1;
		else if(format[*i] == '%')
			s->percentSign = 1;
	}
	return(format[*i]);
}

int parse_format(const char *format, int *i, flags *f, int *width)
{
	(*i)++;
	while (format[*i])
	{
		if (format[*i] == '-')
			f->minus = 1;
		else if (format[*i] == '0')
			f->zero = 1;
		else if (format[*i] == '#')
			f->hashtag = 1;
		else if (format[*i] == ' ')
			f->space = 1;
		else if (format[*i] == '+')
			f->plus = 1;
		else
			break; // Likely reached the specifier
		(*i)++;
	}
	return (format[*i]);
}

int ft_printf(const char *format, ...)
{
	va_list args;
	int char_count = 0;
	int i = 0;
	int width = 0;
	specifiers s = {0};
	flags f = {0};

	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			parse_format(format, &i, &f, &width); // Parse format
			width = ft_check_width(format, i);
			ft_check_specifiers(format, &i, &s);
			char_count += ft_print_text(args, s, f, width); // Print based on parsed specifiers
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			char_count++;
		}
		i++;
	}
	va_end(args);
	return (char_count);
}

// int	ft_printf(const char *format, ...)
// {
// 	va_list	args;
// 	specifiers	s;
// 	char	*copy;
// 	int		i;
// 	int		charnumber;
// 	int		width;

// 	i = 0;
// 	charnumber = 0;
// 	width = 0;
// 	if(!format || *format == '\0')
// 		return (0);
// 	copy = ft_strdup(format);
// 	if(!copy || *copy == '\0')
// 		return (0);
// 	va_start(args, format);
// 	while (copy[i])
// 	{
// 		if (copy[i] == '%' && copy[i] != '\0')
// 		{
// 			//TODO: count or i - how are they handled throught the code?
// 			ft_check_flags(copy, i);
// 			width += ft_check_width(copy, i);
// 			ft_check_specifiers(copy, i, s);
// 			charnumber += ft_print_text(args, s, width); //pass width here
// 		}
// 		else
// 		{
// 			ft_putchar_fd(*copy, 1);
// 			charnumber += 1; // add error check
// 		}
// 		charnumber++;
// 		i++;
// 	}
// 	va_end(args);
// 	return(charnumber);
// }

int	main()
{
	ft_printf("Text here %d\n", 46, 79, -234);
	return(0);
}