/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:28:43 by marvin            #+#    #+#             */
/*   Updated: 2024/06/26 16:14:19 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t length)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)str;
	while (length > 0)
	{
		*ptr = (unsigned char)c;
		ptr++;
		length--;
	}
	return (str);
}

// #include <stdio.h>

// int main()
// {
// 	char str[50] = "GeeksForGeeks is for programming geeks.";

// 	ft_memset(str, '5', 5);
// 	printf("Our function: %s\n", str);

// 	return 0;
// }