/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:28:43 by marvin            #+#    #+#             */
/*   Updated: 2024/07/03 11:41:13 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] && (s[i] != c))
			i++;
	}
	return (count);
}

static void	free_split(char **split, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static void
	bounds(char const *s, char c, size_t *start, size_t *end)
{
	while (s[*start] == c)
		(*start)++;
	*end = *start;
	while (s[*end] != c && s[*end] != '\0')
		(*end)++;
}

char	**ft_split(char const *s, char c)
{
	char	**string;
	size_t	i;
	size_t	start;
	size_t	end;
	size_t	words_count;

	start = 0;
	end = 0;
	i = 0;
	words_count = ft_count(s, c);
	string = (char **)malloc((words_count + 1) * sizeof(char *));
	if (!s || !string)
		return (NULL);
	while (i < words_count)
	{
		bounds(s, c, &start, &end);
		string[i] = ft_substr(s, start, (end - start));
		if (!string[i])
			free_split(string, i);
		start = end;
		i++;
	}
	string[i] = 0;
	return (string);
}
