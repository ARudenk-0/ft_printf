/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:28:43 by marvin            #+#    #+#             */
/*   Updated: 2024/07/01 16:58:36 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	calctrim_indices(const char *s1, const char *set, int *start, int *end)
{
	*start = 0;
	*end = ft_strlen(s1);
	while (s1[*start] && ft_strchr(set, s1[*start]))
		(*start)++;
	while (*end > *start && ft_strchr(set, s1[*end - 1]))
		(*end)--;
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	int		i;
	int		j;
	int		start;
	int		end;

	i = 0;
	start = 0;
	if (!s1 || !set)
		return (NULL);
	calctrim_indices(s1, set, &start, &end);
	j = start;
	result = (char *)malloc((end - start + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (j < end)
		result[i++] = s1[j++];
	result[i] = '\0';
	return (result);
}

// int main()
// {
// 	char text[] = ".....Hi there.....";
// 	char characters[] = ".";
// 	char *trimmed_text;

// 	printf("Untrimmed text: '%s'\n", text);
// 	trimmed_text = ft_strtrim(text, characters);
// 	if (trimmed_text)
// 	{
// 		printf("Trimmed text: '%s'\n", trimmed_text);
// 		free(trimmed_text);
// 	}
// 	else
// 	{
// 		printf("Failed to trim the string.\n");
// 	}

// 	return 0;
// }