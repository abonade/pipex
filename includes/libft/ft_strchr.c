/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibonade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 20:16:55 by aibonade          #+#    #+#             */
/*   Updated: 2023/11/10 15:08:30 by aibonade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*tmp;
	char	tmpc;

	i = 0;
	tmp = (char *)s;
	tmpc = c;
	if (tmpc == 0)
		return (tmp + ft_strlen(s));
	while (tmp[i])
	{
		if (tmp[i] == tmpc)
			return (tmp + i);
		i++;
	}
	return (NULL);
}
