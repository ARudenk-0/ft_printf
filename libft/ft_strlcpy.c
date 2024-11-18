/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:28:43 by marvin            #+#    #+#             */
/*   Updated: 2024/06/28 11:03:45 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	len;
	unsigned int	x;

	i = 0;
	x = 0;
	while (src[x] != '\0')
	{
		x++;
	}
	len = x;
	if (size != 0)
	{
		while (i < size - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (len);
}

// int main ()
// {
// 	char	source[] = "Hello there!";
// 	char	destination[50] = "";

// 	int	howmuch = 8;
// 	printf("The result of copying is: %s", 
//ft_strlcpy(destination, source, howmuch));
// 	return 0;
// }