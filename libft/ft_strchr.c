/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:28:43 by marvin            #+#    #+#             */
/*   Updated: 2024/07/01 16:30:52 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (0);
}

// #include <stdio.h>

// int	main()
// {
// 	char	text[] = ;
// 	char	c = 'f';
// 	char	*result = ft_strchr(text, c); // Store the returned pointer

// 	if (result != NULL) // Check if the character is found
// 		printf("Character '%c' found at position: %ld\n", c, (result - text));
// 	else
// 		printf("Character '%c' not found\n", c);
// 	return (0);
// }

// #include <stdio.h>
// #include <string.h>

// int main() {
//     char *result;

//     // Test 1: Basic Matching
//     result = ft_strchr("hello", 'e');
//     printf("Test 1: %s\n", result ? result : "NULL");

//     // Test 2: Matching at the End
//     result = ft_strchr("hello", 'o');
//     printf("Test 2: %s\n", result ? result : "NULL");

//     // Test 3: No Match
//     result = ft_strchr("hello", 'x');
//     printf("Test 3: %s\n", result ? result : "NULL");

//     // Test 4: Matching Null Terminator
//     result = ft_strchr("hello", '\0');
//     printf("Test 4: %s\n", result ? result : "NULL");

//     // Test 5: Empty String
//     result = ft_strchr("", 'a');
//     printf("Test 5: %s\n", result ? result : "NULL");

//     result = ft_strchr("", '\0');
//     printf("Test 5: %s\n", result ? result : "NULL");

//     // Test 6: NULL String
//     result = ft_strchr(NULL, 'a');
//     printf("Test 6: %s\n", result ? result : "NULL");

//     return 0;
// }