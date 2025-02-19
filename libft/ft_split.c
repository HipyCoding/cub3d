/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 08:46:39 by candrese          #+#    #+#             */
/*   Updated: 2024/03/28 18:46:29 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free(char **ptr, int count)
{
	while (count >= 0)
	{
		free(ptr[count]);
		count--;
	}
	free(ptr);
	return (NULL);
}

static size_t	ft_count(char const *s, char c)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if ((s[i] != c && (i == 0 || s[i - 1] == c)))
			count++;
		i++;
	}
	return (count);
}

static char	*ft_put_string(char const *s, size_t word_len)
{
	size_t	j;
	char	*string;

	j = 0;
	string = (char *)malloc(sizeof(char) * (word_len + 1));
	if (!string)
		return (NULL);
	while (word_len > 0)
	{
		string[j] = (char)s[j];
		j++;
		word_len--;
	}
	string[j] = '\0';
	return (string);
}

char	**ft_split(char const *s, char c)
{
	char		**s2;
	size_t		end;
	size_t		start;
	size_t		words;

	s2 = malloc(sizeof(char *) * (ft_count(s, c) + 1));
	words = 0;
	start = 0;
	if (!s2)
		return (0);
	while (words < ft_count(s, c) && *s)
	{
		while (s[start] == c)
			start++;
		end = start;
		while (s[end] != c && s[end] != '\0')
			end++;
		s2[words] = ft_put_string(&s[start], end - start);
		if (s2[words] == NULL)
			return (ft_free(s2, words));
		start = end;
		words++;
	}
	s2[words] = NULL;
	return (s2);
}
