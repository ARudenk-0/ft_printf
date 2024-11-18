/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:28:43 by marvin            #+#    #+#             */
/*   Updated: 2024/06/28 11:35:59 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dest_length;
	size_t	src_length;

	src_length = ft_strlen(src);
	dest_length = ft_strlen(dst);
	j = dest_length;
	i = 0;
	if (dest_length < size - 1 && size > 0)
	{
		while (src[i] && dest_length + i < size - 1)
		{
			dst[j] = src[i];
			j++;
			i++;
		}
		dst[j] = 0;
	}
	if (dest_length >= size)
		dest_length = size;
	return (dest_length + src_length);
}

// size_t	ft_strlcat(char *dst, const char *src, size_t size)
// {
// 	size_t	dst_len;
// 	size_t	src_len;
// 	size_t	len;
// 	size_t	i;

// 	dst_len = ft_strlen(dst);
// 	src_len = ft_strlen(src);
// 	len = dst_len + src_len;
// 	if (size <= dst_len)
// 		return (size + src_len);
// 	i = 0;
// 	while (i < size - dst_len - 1 && src[i])
// 	{
// 		dst[dst_len + i] = src[i];
// 		i++;
// 	}
// 	if (i < size)
// 		dst[dst_len + i] = '\0';
// 	return (len);
// }

// size_t	ft_strlcat(char *dest, const char *src, size_t size)
// {
// 	char		*p1;
// 	const char	*p2;

// 	p1 = dest;
// 	p2 = src;
// 	while (*dest)
// 	{
// 		p1++;
// 	}
// 	while (*p2 && size - 1)
// 	{
// 		*p1++ = *p2++;
// 		size--;
// 	}
// 	*p1 = '\0';
// 	return (size);
// }

// #include <stdio.h>

// int main(void)
// {
// 	char text1[50] = "Hello ";
// 	char text2[] = "world!!!!fkwfpojepfojpoefjpo";
// 	int maxlength = 10;

// 	ft_strlcat(text1, text2, maxlength);
// 	printf("Concatenated string: %s\n", text1);
// 	return (0);
// }