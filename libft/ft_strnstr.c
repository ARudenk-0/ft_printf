/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:28:43 by marvin            #+#    #+#             */
/*   Updated: 2024/07/03 13:31:22 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;
	size_t	i;
	size_t	j;

	needle_len = ft_strlen(needle);
	i = 0;
	j = 0;
	if (needle_len == 0)
		return ((char *)haystack);
	if (len == 0 || ft_strlen(haystack) < needle_len || len < needle_len)
		return (NULL);
	while (i <= len - needle_len && haystack[i])
	{
		j = 0;
		while (j < needle_len && haystack[i + j] == needle[j])
		{
			j++;
			if (j == needle_len)
				return ((char *)(haystack + i));
		}
		i++;
	}
	return (NULL);
}

// #include <stdlib.h>
// #include <unistd.h>
// #include <stdio.h>
// #include <string.h>

// int	main()
// {
// 	char	text1[] = "abcdefgh";
// 	char	text2[] = "abc";
// 	int	n = 2;

// 	printf("String found at the position: %s", ft_strnstr(text1, text2, n));
// 	// printf("String found at the position: %d", strnstr(text1, text2, n));
// }

// int main()
// {
// 	const char *str;

// 	if (!(str = ft_strnstr("lorem ipsum dolor sit amet", "dolor", 0)))
// 		ft_print_result("NULL");
// 	else
// 		ft_print_result(str);

// 	if (!(str = ft_strnstr("lorem ipsum dolor sit amet", "ipsumm", 30)))
// 		ft_print_result("NULL");
// 	else
// 		ft_print_result(str);
// }