/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougati <abougati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:59:14 by abougati          #+#    #+#             */
/*   Updated: 2025/02/27 18:59:15 by abougati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

int	free_all(char **dub_arr, int pos)
{
	while (pos--)
	{
		free(dub_arr[pos]);
	}
	free(dub_arr);
	return (1);
}

int	allocate_words(char **dub_arr, char *s, char c)
{
	unsigned int	i;
	size_t			len;
	char			*word;

	i = 0;
	while (*s)
	{
		len = 0;
		while (*s == c && *s)
			s++;
		while (*s != c && *s)
		{
			len++;
			s++;
		}
		if (len > 0)
		{
			word = ft_substr(s - len, 0, len);
			if (!word)
				return (free_all(dub_arr, i));
			dub_arr[i++] = word;
		}
	}
	dub_arr[i] = NULL;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	size_t	words;
	char	**dub_arr;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	if (!words)
		return (NULL);
	dub_arr = (char **)malloc(sizeof(char *) * (words + 1));
	if (!dub_arr)
		return (NULL);
	dub_arr[words] = NULL;
	if (allocate_words(dub_arr, (char *)s, c))
		return (NULL);
	return (dub_arr);
}
