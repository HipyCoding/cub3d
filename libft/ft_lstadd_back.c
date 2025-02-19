/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:47:38 by candrese          #+#    #+#             */
/*   Updated: 2023/11/07 18:20:55 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)

{
	t_list	*p;

	p = *lst;
	if (!lst)
		return ;
	if (!p)
	{
		*lst = new;
		return ;
	}
	while (p -> next != NULL)
	{
		p = p -> next;
	}
	p -> next = new;
}
