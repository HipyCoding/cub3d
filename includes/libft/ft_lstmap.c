/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 20:17:46 by candrese          #+#    #+#             */
/*   Updated: 2023/11/15 00:33:10 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*node;
	void	*temp;

	if (!lst || !f || !del)
		return (NULL);
	new = NULL;
	while (lst)
	{
		temp = f(lst -> content);
		node = ft_lstnew(temp);
		if (!node)
		{
			del(temp);
			ft_lstclear (&new, del);
			return (NULL);
		}
		ft_lstadd_back (&new, node);
		lst = lst -> next;
	}
	return (new);
}
