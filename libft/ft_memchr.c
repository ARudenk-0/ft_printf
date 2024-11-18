/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:28:43 by marvin            #+#    #+#             */
/*   Updated: 2024/06/26 16:31:28 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;
	unsigned char		uc;
	size_t				i;

	ptr = (const unsigned char *)s;
	uc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == uc)
			return ((void *)(ptr + i));
		i++;
	}
	return (NULL);
}

// int main()
// {
// 	const char data[] = "Hello, world!";
// 	char *result;

// 	// Test 1: Character 'o' in the string
// 	result = ft_memchr(data, 'o', sizeof(data));
// 	if (result != NULL)
// 		printf("Found 'o' at position: %s\n", result);
// 	else
// 		printf("'o' not found\n");

// 	// Test 2: Character 'z' not in the string
// 	result = ft_memchr(data, 'z', sizeof(data));
// 	if (result != NULL)
// 		printf("Found 'z' at position: %s\n", result);
// 	else
// 		printf("'z' not found\n");

// 	// Test 3: Null character '\0' in the string
// 	result = ft_memchr(data, '\0', sizeof(data));
// 	if (result != NULL)
// 		printf("Found '\\0' at position: %s\n", result);
// 	else
// 		printf("'\\0' not found\n");

// 	return 0;
// }