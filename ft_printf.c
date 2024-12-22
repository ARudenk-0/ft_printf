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

//TODO: break down into smaller functions (char+str+pointer/dec+int+unsigned/hex+Hex) 
// + create the additional files that have these functions
int	ft_print_arg(va_list args, t_format_info *info)
{
	int		count;
	char	*str;

	count = 0;
	if (info->s.character)
	{
		char ch = (char)va_arg(args, int);
		char tmp[2];
		tmp[0] = ch;
		tmp[1] = '\0';
		count += ft_print_char_with_flags(tmp[0], info);
	}
	else if (info->s.string)
	{
		str = va_arg(args, char *);
		count += ft_format_output(str, info);
	}
	else if (info->s.pointer)
	{
		void *ptr = va_arg(args, void *);
		count += ft_print_pointer(ptr);
	}
	else if (info->s.decmal || info->s.integr)
		count += ft_print_number_signed((long)va_arg(args, int), info);
	else if (info->s.unsigned_des)
		count += ft_print_number_unsigned((unsigned long)va_arg(args, unsigned int), info, 10, 0);
	else if (info->s.unsignd_lower)
		{
			unsigned long n = (unsigned long)va_arg(args, unsigned int);
			count += ft_print_number_unsigned(n, info, 16, 0);
		}
	else if (info->s.unsignd_upper)
		{
			unsigned long n = (unsigned long)va_arg(args, unsigned int);
			count += ft_print_number_unsigned(n, info, 16, 1);
		}
	else if (info->s.percent_sign)
		count += ft_putchar_fd_count('%', 1); // ensure we add to count
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
	if (format[*i] == 'c') 	// We only read ONE character for the specifier
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
	return (format[*i]); 	// We return the character if needed. Or just do:
}

int	parse_format(const char *format, int *i, t_format_info *info)
{
	while (format[*i]) // Parse possible flags
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
	if (ft_isdigit(format[*i])) // Parse width (if present)
		info->width = ft_check_width(format, i);
	ft_parse_precision(format, i, info);
	if (format[*i] && (ft_isalpha(format[*i]) || format[*i] == '%')) // Now we expect exactly one specifier (e.g. 'c', 's', etc.)
		ft_check_specifiers(format, i, info);
	return (*i);
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
	while (format[i])
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
			char_count += ft_putchar_fd_count(format[i], 1);
		}
		i++;
	}
	va_end(args);
	return (char_count);
}
