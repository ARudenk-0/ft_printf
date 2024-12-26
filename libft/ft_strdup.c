/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:28:43 by marvin            #+#    #+#             */
/*   Updated: 2024/12/26 14:51:41 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	char	*start;
	size_t	len;

	len = ft_strlen((char *)s);
	dup = (char *)malloc((len + 1) * sizeof(char));
	start = dup;
	if (dup != NULL)
	{
		while (*s)
			*dup++ = *s++;
		*dup = '\0';
		return (start);
	}
	else if (dup == NULL)
		free (dup);
	return (NULL);
}

// #include <stdio.h>

// int	main()
// {
// 	char	text[] = "Hello";

// 	printf("Result of duplication: %s\n", ft_strdup(text));
// 	return 0;
// }