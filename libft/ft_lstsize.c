/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:14:29 by candrese          #+#    #+#             */
/*   Updated: 2023/11/07 17:26:31 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)

{
	size_t	i;
	t_list	*p;

	p = lst;
	i = 0;
	if (!lst)
		return (0);
	while (p -> next != NULL)
	{
		p = p -> next;
		i++;
	}
	i++;
	return (i);
}
