/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibonade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:36:38 by aibonade          #+#    #+#             */
/*   Updated: 2023/11/10 19:02:44 by aibonade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	len1;
	size_t	len2;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new = malloc((len1 + len2 + 1) * sizeof(char));
	if (!new)
		return (NULL);
	new = ft_memcpy(new, s1, len1);
	i = 0;
	while (s2[i])
	{
		new[len1 + i] = s2[i];
		i++;
	}
	new[len1 + i] = '\0';
	return (new);
}
