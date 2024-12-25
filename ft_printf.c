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

int	ft_print_arg(va_list args, t_format_info *info)
{
	int		count;

	count = 0;
	count += ft_print_arg_csp(args, info, count);
	if (info->s.decmal || info->s.integr)
		count += ft_print_number_signed((long)va_arg(args, int), info);
	else if (info->s.unsigned_des)
		count += ft_print_num_unsgnd((unsigned long)va_arg(args, unsigned int),
				info, 10, 0);
	else if (info->s.unsignd_lower || info->s.unsignd_upper)
		count += ft_print_arg_unsigned(args, info, count);
	else if (info->s.percent_sign)
		count += ft_putchar_fd_count('%', 1);
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
	if (ft_isdigit(format[*i]))
		info->width = ft_check_width(format, i);
	ft_parse_precision(format, i, info);
	if (format[*i] && (ft_isalpha(format[*i]) || format[*i] == '%'))
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
