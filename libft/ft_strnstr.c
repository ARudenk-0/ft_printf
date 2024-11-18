/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:28:43 by marvin            #+#    #+#             */
/*   Updated: 2024/07/09 11:40:58 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;
	size_t	i;
	size_t	j;

	if (!haystack || !needle)
		return (NULL);
	needle_len = ft_strlen(needle);
	i = 0;
	if (needle_len == 0)
		return ((char *)(haystack));
	if (len < needle_len)
		return (NULL);
	if (len == 0 || ft_strlen(haystack) < needle_len)
		return (NULL);
	while (i <= len - needle_len && haystack[i])
	{
		j = 0;
		while (j < needle_len && haystack[i + j] == needle[j])
		{
			j++;
			if (j == needle_len)
				return ((char *)(haystack + i));
		}
		i++;
	}
	return (NULL);
}

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
// 	const char *str;
// 	int			arg;

// 	if (argc == 1)
// 		return (0);
// 	else if ((arg = atoi(argv[1])) == 1)
// 	{
// 		if (!(str = ft_strnstr("lorem ipsum dolor sit amet", "lorem", 15)))
// 			ft_print_result("NULL");
// 		else
// 			ft_print_result(str);
// 	}
// 	else if (arg == 2)
// 	{
// 		if (!(str = ft_strnstr("lorem ipsum dolor sit amet", "ipsum", 15)))
// 			ft_print_result("NULL");
// 		else
// 			ft_print_result(str);
// 	}
// 	else if (arg == 3)
// 	{
// 		if (!(str = ft_strnstr("lorem ipsum dolor sit 
// lorem ipsum dolor", "ipsum", 35)))
// 			ft_print_result("NULL");
// 		else
// 			ft_print_result(str);
// 	}
// 	else if (arg == 4)
// 	{
// 		if (!(str = ft_strnstr("lorem ipsum dolor sit amet", "", 10)))
// 			ft_print_result("NULL");
// 		else
// 			ft_print_result(str);
// 	}
// 	else if (arg == 5)
// 	{
// 		if (!(str = ft_strnstr("lorem ipsum dolor sit amet", "ipsumm", 30)))
// 			ft_print_result("NULL");
// 		else
// 			ft_print_result(str);
// 	}
// 	else if (arg == 6)
// 	{
// 		if (!(str = ft_strnstr("lorem ipsum dolor sit amet", "dol", 30)))
// 			ft_print_result("NULL");
// 		else
// 			ft_print_result(str);
// 	}
// 	else if (arg == 7)
// 	{
// 		if (!(str = ft_strnstr("lorem ipsum 
// dolor sit amet", "consectetur", 30)))
// 			ft_print_result("NULL");
// 		else
// 			ft_print_result(str);
// 	}
// 	else if (arg == 8)
// 	{
// 		if (!(str = ft_strnstr("lorem ipsum dolor sit amet", "sit", 10)))
// 			ft_print_result("NULL");
// 		else
// 			ft_print_result(str);
// 	}
// 	else if (arg == 9)
// 	{
// 		if (!(str = ft_strnstr("lorem ipsum dolor sit amet", "dolor", 15)))
// 			ft_print_result("NULL");
// 		else
// 			ft_print_result(str);
// 	}
// 	else if (arg == 10)
// 	{
// 		if (!(str = ft_strnstr("lorem ipsum dolor sit amet", "dolor", 0)))
// 			ft_print_result("NULL");
// 		else
// 			ft_print_result(str);
// 	}
// 	return (0);
// }

// int	main()
// {
// 	// char	text1[] = "OneTwoThree";
// 	// char	text2[] = "Three";
// 	// int	n = 5;

// 	// printf("String found at the position: %s", ft_strnstr(text1, text2, n));
// 	// printf("String found at the position: %s", strnstr(text1, text2, n));
// }

// int main()
// {
// 	const char *str;

// 	if (!(str = ft_strnstr("lorem ipsum dolor sit amet", "dolor", 0)))
// 		ft_print_result("NULL");
// 	else
// 		ft_print_result(str);

// 	if (!(str = ft_strnstr("lorem ipsum dolor sit amet", "ipsumm", 30)))
// 		ft_print_result("NULL");
// 	else
// 		ft_print_result(str);
// }