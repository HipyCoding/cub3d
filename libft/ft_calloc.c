/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 03:28:31 by candrese          #+#    #+#             */
/*   Updated: 2024/10/29 15:59:17 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)

{
	void	*str;

	str = (void *)malloc(count * size);
	if (str)
	{
		ft_bzero(str, count * size);
	}
	return (str);
}
