/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:28:43 by marvin            #+#    #+#             */
/*   Updated: 2024/06/26 17:39:47 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	int	numeric;
	int	alphab;

	numeric = c >= 48 && c <= 57;
	alphab = (c > 64 && c < 91) || (c >= 97 && c <= 122);
	if (!numeric && !alphab)
		return (0);
	return (1);
}

// int main ()
// {
// 	int i = '8';

// 	printf("The result is: %d", ft_isalnum(i));
// 	return 0;
// }