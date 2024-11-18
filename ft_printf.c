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

int	ft_check_flags(char *format, int i)
{
	flags	flags;

	if()
	{

	}
	
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
	while (format[i])
	{
		if (format[i] == '%' && format[i] != '/0')
			ft_check_flags(format[i], i);
		else
			i++;
	}
	va_end(args);
	return(i);
}