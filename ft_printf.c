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

char	ft_print_arg(va_list args, t_format_info *info)
{
	int		count;
	char	*str;

	count = 0;
	if (info->s.character || info -> s.string)
	{
		str = va_arg(args, char *);
		ft_format_output(str, info); // Merged char and str, because char is a str[2]
	}
	else if (info->s.pointer)
		ft_print_pointer(va_arg(args, void *));
	else if (info->s.decmal || info->s.integr)
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (info->s.unsigned_des)
		ft_putnbr_fd(va_arg(args, unsigned int), 1);
	else if (info->s.unsignd_lower)
		ft_print_hex_lowercase(va_arg(args, unsigned int), 1);
	else if (info->s.unsignd_upper)
		ft_print_hex_uppercase(va_arg(args, unsigned int), 1);
	else if (info->s.percent_sign)
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

int	ft_check_specifiers(const char *format, int *i, t_format_info *info)
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
			info->s.unsigned_des = 1;
		else if (format[*i] == 'x')
			info->s.unsignd_lower = 1;
		else if (format[*i] == 'X')
			info->s.unsignd_upper = 1;
		else if (format[*i] == '%')
			info->s.percent_sign = 1;
	}
	return (format[*i]);
}

int	parse_format(const char *format, int *i, t_format_info *info)
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
	else if (ft_isalpha(format[*i++]) || ft_strchr(&format[*i], '%'))
		ft_check_specifiers(format, i, info);
	//TODO: prepare a buffer according to the flags: padding, zeros, minus sign etc.
	return (format[*i]);
}

int	ft_printf(const char *format, ...)
{
	int				char_count;
	int				i;
	t_format_info	info;
	va_list			args;

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
			char_count += ft_print_arg(args, &info);
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
// 			charnumber += ft_print_arg(args, s, width); //pass width here
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