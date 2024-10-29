/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibonade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:40:57 by aibonade          #+#    #+#             */
/*   Updated: 2023/11/10 15:13:45 by aibonade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*tmp;

	i = ft_strlen(s);
	tmp = (char *)s;
	while (i >= 0)
	{
		if (tmp[i] == (char)c)
			return (tmp + i);
		i--;
	}
	return (NULL);
}
