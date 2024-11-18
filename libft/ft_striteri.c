/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:31:35 by arudenko          #+#    #+#             */
/*   Updated: 2024/06/28 15:34:12 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// static void	f(unsigned int i, char *b)
// {
// 	if (i != 0)
// 		*b = *b + 5;
// 	else
// 		*b = *b - 5;
// }

// #include <stdio.h>

// int	main()
// {
// 	char	text[] = "Hello guys";

// 	ft_striteri(text, f);
// 	printf("%s\n",text); 
// 	return (0);
// }