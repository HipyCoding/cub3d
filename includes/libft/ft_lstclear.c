/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:38:58 by candrese          #+#    #+#             */
/*   Updated: 2023/11/07 20:05:41 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*p;

	if (!lst)
		return ;
	if (!del)
		return ;
	while (*lst != NULL)
	{
		(del)((*lst)-> content);
		p = (*lst)-> next;
		free(*lst);
		*lst = p;
	}
	*lst = NULL;
}
