/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 04:02:28 by candrese          #+#    #+#             */
/*   Updated: 2023/10/27 23:47:10 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)

{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = ft_strlen(s1);
	str = 0;
	if (s1)
	{
		while (s1[i] != '\0' && ft_strchr(set, s1[i]))
			i++;
		while (ft_strrchr(set, s1[j]) && j > i)
			j--;
		if (j == 0)
			j = -1;
		str = (char *)malloc(sizeof(char) * (j - i + 1 + 1));
		if (!str)
			return (NULL);
		ft_strlcpy(str, &s1[i], j - i + 1 + 1);
	}
	return (str);
}

//len = j - i + 1;

// static char	*malloc_and_copy(const char *s, int start, int len)
// {
// 	int		i;
// 	char	*new;

// 	i = 0;
// 	new = malloc(sizeof(char) * (len + 1));
// 	if (new == NULL)
// 		return (NULL);
// 	while (len > i)
// 	{
// 		new[i] = s[start + i];
// 		i++;
// 	}
// 	new[i] = '\0';
// 	return (new);
// }

// char	*ft_strtrim(char const *s1, char const *set)
// {
// 	char	*new;
// 	int		start;
// 	int		end;
// 	int		len;
// 	int		new_len;

// 	len = ft_strlen(s1);
// 	start = 0;
// 	end = 0;
// 	while (s1[start] && ft_strchr(set, s1[start]))
// 		start++;
// 	end = len - 1;
// 	while (end > start && ft_strrchr(set, s1[end]))
// 		end--;
// 	new_len = end - start + 1;
// 	new = malloc_and_copy(s1, start, new_len);
// 	return (new);
// }
