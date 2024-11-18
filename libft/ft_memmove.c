/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:28:43 by marvin            #+#    #+#             */
/*   Updated: 2024/06/28 15:26:30 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t length)
{
	const unsigned char	*s;
	unsigned char		*d;

	if (!dest && !src)
		return (dest);
	if (dest < src)
		return (ft_memcpy(dest, src, length));
	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	while (length--)
		d[length] = s[length];
	return (dest);
}

// #include <string.h>
// #include <stdio.h>

// int main()
// {
// 	// char *text1 = "There";
// 	// char *text2 = "Hi everyone";
// 	// unsigned int a = 0;

// 	char *text1 = "woehfosfdv";
// 	char text2[50] = "";
// 	size_t a = 5;

// 	printf("Dest: %s\n", (char *)ft_memmove(text2, text1, a));
// 	printf("Dest: %s\n", (char *)memmove(text2, text1, a));
// 	return (0);

// }

// #include <stdlib.h>
// #include <unistd.h>
// #include <string.h>

// int		main(int argc, const char *argv[])
// {
// 	char	src[] = "lorem ipsum dolor sit amet";
// 	char	*dest;
// 	int		arg;

// 	dest = src + 1;
// 	if (argc == 1)
// 		return (0);
// 	else if ((arg = atoi(argv[1])) == 1)
// 	{
// 		if (dest != ft_memmove(dest, "consectetur", 5))
// 			write(1, "dest's adress was not returned\n", 31);
// 		write(1, dest, 22);
// 	}
// 	else if (arg == 2)
// 	{
// 		if (dest != ft_memmove(dest, "con\0sec\0\0te\0tur", 10))
// 			write(1, "dest's adress was not returned\n", 31);
// 		write(1, dest, 22);
// 	}
// 	else if (arg == 3)
// 	{
// 		if (dest != ft_memmove(dest, src, 8))
// 			write(1, "dest's adress was not returned\n", 31);
// 		write(1, dest, 22);
// 	}
// 	else if (arg == 4)
// 	{
// 		if (src != ft_memmove(src, dest, 8))
// 			write(1, "dest's adress was not returned\n", 31);
// 		write(1, dest, 22);
// 	}
// 	else if (arg == 5)
// 	{
// 		if (src != ft_memmove(src, dest, 0))
// 			write(1, "dest's adress was not returned\n", 31);
// 		write(1, dest, 22);
// 	}
// 	return (0);
// }