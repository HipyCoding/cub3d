/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:56:14 by candrese          #+#    #+#             */
/*   Updated: 2023/10/25 05:02:09 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)

{
	size_t	d;
	size_t	s;

	d = 0;
	s = 0;
	while (dst[d] != '\0' && d < dstsize)
		d++;
	while (src[s] != '\0' && (s + d + 1) < dstsize)
	{
		dst[d + s] = src[s];
		s++;
	}
	if (d < dstsize)
		dst[s + d] = '\0';
	return (ft_strlen(src) + d);
}
