/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:28:43 by marvin            #+#    #+#             */
/*   Updated: 2024/06/26 15:37:40 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	int	lowercase;
	int	uppercase;

	lowercase = c >= 'a' && c <= 'z';
	uppercase = c >= 'A' && c <= 'Z';
	if (!lowercase && !uppercase)
		return (0);
	return (1);
}

// int main ()
// {
// 	int i = 'j';

// 	printf("The result is: %d", ft_isalpha(i));
// 	return 0;
// }