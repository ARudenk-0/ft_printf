/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:28:43 by marvin            #+#    #+#             */
/*   Updated: 2024/07/01 12:48:22 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*string;
	unsigned int	i;
	unsigned int	length;

	i = 0;
	length = ft_strlen((const char *)s);
	string = (char *)malloc((length + 1) * sizeof(char));
	if (!string)
		return (NULL);
	while (s[i] && i < length)
	{
		string[i] = f(i, s[i]);
		i++;
	}
	string[i] = '\0';
	return (string);
}

// static char	f(unsigned int i, char b)
// {
// 	if (i != 0)
// 		b = b + 5;
// 	else
// 		b = b - 5;
// 	return (b);
// }

// int	main()
// {
// 	char	*text = "Hello guys";
// 	char	*modified_text;

// 	printf("Not modified yet: %s\n", text);
// 	modified_text = ft_strmapi(text,f);
// 	printf("Modified: %s\n", modified_text);

// 	free(modified_text);
// 	return (0);
// }