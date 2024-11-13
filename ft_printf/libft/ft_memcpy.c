/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:28:43 by marvin            #+#    #+#             */
/*   Updated: 2024/06/28 15:25:37 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	int					i;

	i = 0;
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (!d && !s)
		return (d);
	while (n > 0)
	{
		d[i] = s[i];
		i++;
		n--;
	}
	return (d);
}

// int main()
// {
// 	char text1[] = "hiwefnodhrfthd";
// 	char text2[] = "894186489";
// 	size_t a = 8;

// 	printf("Dest: %s\n", (char *)ft_memcpy(text1, text2, a));
// 	return (0);
// }

// #include <stdlib.h>
// #include <unistd.h>
// #include <string.h>

// int		main(int argc, const char *argv[])
// {
// 	void	*mem;
// 	int		arg;

// 	alarm(5);
// 	if (!(mem = malloc(sizeof(*mem) * 30)) || argc == 1)
// 		return (0);
// 	memset(mem, 'j', 30);
// 	if ((arg = atoi(argv[1])) == 1)
// 	{
// 		if (mem != ft_memcpy(mem, "zyxwvutsrqponmlkjihgfedcba", 14))
// 			write(1, "dest's adress was not returned\n", 31);
// 		write(1, mem, 30);
// 	}
// 	else if (arg == 2)
// 	{
// 		if (mem != ft_memcpy(mem, "zyxwvutst", 0))
// 			write(1, "dest's adress was not returned\n", 31);
// 		write(1, mem, 30);
// 	}
// 	else if (arg == 3)
// 	{
// 		if (mem != ft_memcpy(mem, "zy\0xw\0vu\0\0tsr", 11))
// 			write(1, "dest's adress was not returned\n", 31);
// 		write(1, mem, 30);
// 	}
// 	return (0);
// }