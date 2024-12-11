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

char	ft_print_text(va_list args, format_info *info)
{
	int	count;

	count = 0;
	if (info->s.character)
		ft_putchar_fd(va_arg(args, int), 1); //had to change va_args(args, char) to ~(, int) -> what is the logic behind it?
	else if (info->s.string)
	{
		if (!va_arg(args, char *))
			ft_putstr_fd("(null)", 1);
		else
			ft_putstr_fd(va_arg(args, char *), 1);
	}
	else if (info->s.pointer)
		ft_print_pointer((unsigned long int)va_arg(args, void *));
	else if (info->s.decmal || info->s.integr)
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (info->s.unsignedDes)
		ft_putdec_nbr(va_arg(args, unsigned int), 1); //TODO
	else if (info->s.unsigndLower)
		ft_print_hex_lowercase(va_arg(args, unsigned int), 1);
	else if (info->s.unsigndUpper)
		ft_print_hex_uppercase(va_arg(args, unsigned int), 1);
	else if (info->s.percentSign)
		ft_putchar_fd('%', 1);
	return (count);
}

int	ft_check_width(const char *format, int *i)
{
	int	width;

	width = 0;
	while (format[*i] && ft_isdigit(format[*i]))
	{
		width = (width * 10) + (format[*i] - '0');
		(*i)++;
	}
	return (width);
}

int	ft_check_specifiers(char *format, int *i, format_info *info)
{
	while (format[*i])
	{
		(*i)++;
		if (format[*i] == 'c')
			info->s.character = 1;
		else if (format[*i] == 's')
			info->s.string = 1;
		else if (format[*i] == 'p')
			info->s.pointer = 1;
		else if (format[*i] == 'd')
			info->s.decmal = 1;
		else if (format[*i] == 'i')
			info->s.integr = 1;
		else if (format[*i] == 'u')
			info->s.unsignedDes = 1;
		else if (format[*i] == 'x')
			info->s.unsigndLower = 1;
		else if (format[*i] == 'X')
			info->s.unsigndUpper = 1;
		else if (format[*i] == '%')
			info->s.percentSign = 1;
	}
	return (format[*i]);
}

int	parse_format(const char *format, int *i, format_info *info)
{
	while (format[*i])
	{
		if (format[*i] == '-')
			info->f.minus = 1;
		else if (format[*i] == '0')
			info->f.zero = 1;
		else if (format[*i] == '#')
			info->f.hashtag = 1;
		else if (format[*i] == ' ')
			info->f.space = 1;
		else if (format[*i] == '+')
			info->f.plus = 1;
		else
			break ;
		(*i)++;
	}
	if (ft_isdigit(format[*i++]))
		info->width = ft_check_width(format, i);
	else if (ft_isalpha(format[*i++]) || ft_strchr(format[*i], '%'))
		ft_check_specifiers(format, &i, &info);
	//TODO: prepare a buffer according to the flags: padding, zeros, minus sign etc.
	return (format[*i]);
}

int	ft_printf(const char *format, ...)
{
	int			char_count;
	int			i;
	format_info	info;
	va_list		args;

	i = 0;
	char_count = 0;
	va_start(args, format);
	while (format[i++])
	{
		initialize_data(&info);
		if (format[i] == '%')
		{
			i++;
			parse_format(format, &i, &info);
			char_count += ft_print_text(args, &info);
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			char_count++;
		}
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
// 	if (!format || *format == '\0')
// 		return (0);
// 	copy = ft_strdup(format);
// 	if (!copy || *copy == '\0')
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
// 	return (charnumber);
// }

// int	main()
// {
// 	ft_printf("Text here %d\n", 46, 79, -234);
// 	return (0);
// }