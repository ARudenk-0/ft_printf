/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:29:51 by arudenko          #+#    #+#             */
/*   Updated: 2024/07/01 18:19:16 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = ft_strlen(s);
	if ((char)c == 0)
		return ((char *)s + i);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}

// char	*ft_strrchr(const char *s, int c)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i])
// 		i++;
// 	if ((unsigned int)c == '\0')
// 		return ((char *)(s + i));
// 	while (i >= 0)
// 	{
// 		if ((unsigned int)s[i] == (unsigned int)c)
// 			return ((char *)(s + i));
// 		i--;
// 	}
// 	return (NULL);
// }

// int	main()
// {
// 	char	text[] = "Hello friends";
// 	int	c = 'f';
// 	char	*result = ft_strrchr(text, c); // Store the returned pointer

// 	if (result != NULL) // Check if the character is found
// 		printf("Character '%c' found at position: %ld\n", c, result - text);
// 	else
// 		printf("Character '%c' not found\n", c);
// 	return (0);
// }

// #include <stdio.h>
// #include <string.h>

// int main() {
//     char *result;

//     // Test 1: Basic Matching
//     result = ft_strrchr("hello", 'e');
//     printf("Test 1: %s\n", result ? result : "NULL");

//     // Test 2: Matching at the End
//     result = ft_strrchr("hello", 'o');
//     printf("Test 2: %s\n", result ? result : "NULL");

//     // Test 3: No Match
//     result = ft_strrchr("hello", 'x');
//     printf("Test 3: %s\n", result ? result : "NULL");

//     // Test 4: Matching Null Terminator
//     result = ft_strrchr("hello", '\0');
//     printf("Test 4: %s\n", result ? result : "NULL");

//     // Test 5: Empty String
//     result = ft_strrchr("", 'a');
//     printf("Test 5: %s\n", result ? result : "NULL");

//     // Test 6:
//     result = ft_strrchr("", '\0');
//     printf("Test 6: %s\n", result ? result : "NULL");

//     // Test 7: NULL String
//     result = ft_strrchr(NULL, 'a');
//     printf("Test 7: %s\n", result ? result : "NULL");

//     // Test 7: Character Outside Typical ASCII Range
//     result = ft_strrchr("hello", 't' + 256);
//     printf("Test 8: %s\n", result ? result : "NULL");

//     return 0;
// }
