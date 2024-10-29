/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibonade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:19:24 by aibonade          #+#    #+#             */
/*   Updated: 2023/11/16 18:52:37 by aibonade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*tmp_nxt;

	if (lst && *lst)
	{
		tmp = *lst;
		tmp_nxt = tmp->next;
		ft_lstdelone(tmp, (*del));
		while (tmp_nxt)
		{
			tmp = tmp_nxt;
			tmp_nxt = tmp->next;
			ft_lstdelone(tmp, (*del));
		}
		*lst = NULL;
	}
}
