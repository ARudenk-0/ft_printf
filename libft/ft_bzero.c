/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 22:21:19 by arudenko          #+#    #+#             */
/*   Updated: 2024/06/26 15:38:04 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t length)
{
	char	*ptr;

	ptr = (char *)str;
	while (length > 0)
	{
		ptr[length - 1] = '\0';
		length--;
	}
}

// int main()
// {
// 	char text[] = "Hello, friends!";
// 	int n = 5;
// 	// bzero(text, n);
// 	// printf("%s\n", text);

// 	ft_bzero(text, n);  // Modify the string
// 	// printf("%s\n", text);  // Print the modified string

// 	for (size_t i = 0; i < sizeof(text); i++)
// 	{
// 		if (text[i] == '\0')
// 			printf("\\0");
// 		else
// 			printf("%c", text[i]);
// 	}
// 	printf("\n");
// 	return 0;
// }