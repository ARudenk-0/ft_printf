/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ltoa_signed_utils.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 16:35:51 by arudenko          #+#    #+#             */
/*   Updated: 2024/12/27 17:21:11 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_add_sign(char *digits, t_format_info *info, int negative)
{
	char	*result;

	if (negative)
		result = ft_strjoin("-", digits);
	else if (info->f.plus == 1)
		result = ft_strjoin("+", digits);
	else if (info->f.space == 1)
		result = ft_strjoin(" ", digits);
	else
		result = ft_strdup(digits);
	free(digits);
	return (result);
}

char	*ft_make_zeros(int needed)
{
	char	*z;
	int		i;

	z = (char *)malloc(needed + 1);
	i = 0;
	if (!z)
		return (NULL);
	while (i < needed)
	{
		z[i] = '0';
		i++;
	}
	z[i] = '\0';
	return (z);
}
