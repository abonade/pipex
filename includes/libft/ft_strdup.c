/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibonade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:28:24 by aibonade          #+#    #+#             */
/*   Updated: 2023/11/10 16:03:32 by aibonade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*new;

	len = ft_strlen(s);
	new = malloc(len * sizeof(char) + 1);
	if (!new)
		return (NULL);
	new = ft_memcpy(new, s, len * sizeof(char));
	new[len] = '\0';
	return (new);
}
