/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:44:49 by candrese          #+#    #+#             */
/*   Updated: 2023/11/07 17:27:44 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)

{
	t_list	*p;

	p = lst;
	if (!p)
		return (0);
	while (p -> next != NULL)
	{
		p = p -> next;
	}
	return (p);
}
