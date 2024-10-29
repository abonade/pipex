/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibonade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:46:29 by aibonade          #+#    #+#             */
/*   Updated: 2023/11/10 13:09:01 by aibonade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*tmpsrc;
	unsigned char	*tmpdest;

	if (n == 0)
		return (dest);
	if (dest > src)
	{
		i = n - 1;
		tmpsrc = (unsigned char *)src;
		tmpdest = (unsigned char *)dest;
		while (i > 0)
		{
			tmpdest[i] = tmpsrc[i];
			i--;
		}
		tmpdest[i] = tmpsrc[i];
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
