/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibonade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:03:20 by aibonade          #+#    #+#             */
/*   Updated: 2023/11/16 18:21:50 by aibonade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*nw_elmnt;
	t_list	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	new_lst = NULL;
	nw_elmnt = ft_lstnew((*f)(tmp->content));
	if (!nw_elmnt)
		return (new_lst);
	ft_lstadd_front(&new_lst, nw_elmnt);
	while (tmp->next)
	{
		tmp = tmp->next;
		nw_elmnt = ft_lstnew((*f)(tmp->content));
		if (!nw_elmnt)
		{
			ft_lstclear(&new_lst, (*del));
			return (new_lst);
		}
		ft_lstadd_back(&new_lst, nw_elmnt);
	}
	return (new_lst);
}
