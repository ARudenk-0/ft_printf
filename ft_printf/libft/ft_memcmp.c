/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:23:16 by arudenko          #+#    #+#             */
/*   Updated: 2024/06/26 16:28:47 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *buf1, const void *buf2, size_t count)
{
	const unsigned char	*b1;
	const unsigned char	*b2;

	b1 = (const unsigned char *)buf1;
	b2 = (const unsigned char *)buf2;
	while (count--)
	{
		if (*b1 != *b2)
		{
			return (*b1 - *b2);
		}
		b1++;
		b2++;
	}
	return (0);
}

// int main()
// {
// 	char text1[] = "Hellok";
// 	char text2[] = "Hellok";

// 	size_t size = sizeof(text1);
// 	int result = ft_memcmp(text1, text2, size);
// 	printf("Comparison result: %d\n", result);

// 	size = sizeof(text2);
// 	result = ft_memcmp(text1, text2, size);
// 	printf("Comparison result: %d\n", result);

// 	size = 5;
// 	result = ft_memcmp(text1, text2, size);
// 	printf("Comparison result: %d\n", result);

// 	size = 10;
// 	result = ft_memcmp(text1, text2, size);
// 	printf("Comparison result: %d\n", result);
// 	return 0;
// }