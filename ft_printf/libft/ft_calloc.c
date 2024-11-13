/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 22:21:32 by arudenko          #+#    #+#             */
/*   Updated: 2024/07/09 11:33:33 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*ptr;
	size_t	b;

	if (nitems == 0 || size == 0)
	{
		nitems = 1;
		size = 1;
	}
	b = nitems * size;
	ptr = malloc(b);
	if (ptr != NULL)
	{
		ft_memset(ptr, '\0', b);
		return (ptr);
	}
	else
		return (NULL);
}

// int main ()
// {
// 	int n = 5;
// 	int a = sizeof(n);

// 	ft_calloc(n, a);

// 	printf("%d", ft_calloc(n, a));
// 	return 0;
// }

// int main()
// {
// 	int n = 5;
// 	size_t size = sizeof(int);

// 	// Call ft_calloc to allocate and initialize memory
// 	int *arr = (int *)ft_calloc(n, size);
// 	if (arr == NULL)
// 	{
// 		printf("Memory allocation failed\n");
// 		return 1;
// 	}

// 	// Print the allocated and zero-initialized array
// 	for (int i = 0; i < n; i++)
// 	{
// 		printf("%d ", arr[i]);  // Output will be: 0 0 0 0 0
// 	}
// 	printf("\n");

// 	// Free the allocated memory
// 	free(arr);

// 	return 0;
// }
