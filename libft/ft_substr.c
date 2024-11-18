/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:28:43 by marvin            #+#    #+#             */
/*   Updated: 2024/07/03 11:31:22 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	sub = (char *)malloc(((len + 1) * sizeof(char)));
	if (!s || !sub)
		return (NULL);
	if (sub != NULL)
	{
		while (s[i])
		{
			if (i >= start && j < len)
				sub[j++] = s[i];
			i++;
		}
		sub[j] = 0;
		return (sub);
	}
	return (NULL);
}

// int main()
// {
// 	char	source[] = "Hi there guys!!!Kefgrg";
// 	int	strt = 7;
// 	int	n = 5;

//     printf("Old string: %s\n", source);
// 	printf("New string: %s\n", ft_substr(source, strt, n));
// 	return (0);
// }

// #include <stdlib.h>
// #include <unistd.h>

// void	ft_print_result(char const *s)
// {
// 	int		len;

// 	len = 0;
// 	while (s[len])
// 		len++;
// 	write(1, s, len);
// }

// int		main(int argc, const char *argv[])
// {
// 	char	str[] = "lorem ipsum dolor sit amet";
// 	char	*strsub;
// 	int		arg;

// 	if (argc == 1)
// 		return (0);
// 	else if ((arg = atoi(argv[1])) == 1)
// 	{
// 		if (!(strsub = ft_substr(str, 0, 10)))
// 			ft_print_result("NULL");
// 		else
// 			ft_print_result(strsub);
// 		if (str == strsub)
// 			ft_print_result("\nA new string was not returned");
// 	}
// 	else if (arg == 2)
// 	{
// 		if (!(strsub = ft_substr(str, 7, 10)))
// 			ft_print_result("NULL");
// 		else
// 			ft_print_result(strsub);
// 		if (str == strsub)
// 			ft_print_result("\nA new string was not returned");
// 	}
// 	else if (arg == 3)
// 	{
// 		if (!(strsub = ft_substr(str, 7, 0)))
// 			ft_print_result("NULL");
// 		else
// 			ft_print_result(strsub);
// 		if (str == strsub)
// 			ft_print_result("\nA new string was not returned");
// 	}
// 	else if (arg == 4)
// 	{
// 		if (!(strsub = ft_substr(str, 0, 0)))
// 			ft_print_result("NULL");
// 		else
// 			ft_print_result(strsub);
// 		if (str == strsub)
// 			ft_print_result("\nA new string was not returned");
// 	}
// 	else if (arg == 5)
// 	{
// 		char *bullshit;
// 		if (!(strsub = ft_substr(str, 400, 20)))
// 			ft_print_result("NULL");
// 		else
// 		{
// 			bullshit = (char *)&strsub[30];
// 			bullshit = "FULL BULLSHIT";
// 			if (strsub)
// 				ft_print_result(strsub);
// 			else
// 				ft_print_result("rip");
// 		}
// 		if (str == strsub)
// 			ft_print_result("\nA new string was not returned");
// 		(void)bullshit;
// 	}
// 	return (0);
// }