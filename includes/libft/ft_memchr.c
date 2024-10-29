/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibonade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:12:03 by aibonade          #+#    #+#             */
/*   Updated: 2023/11/10 13:10:17 by aibonade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tmp;
	unsigned char	tosearch;
	size_t			i;

	tmp = (unsigned char *)s;
	i = 0;
	tosearch = (unsigned char)c;
	while (i < n)
	{
		if (tmp[i] == tosearch)
			return (tmp + i);
		i++;
	}
	return (NULL);
}
