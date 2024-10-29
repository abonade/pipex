/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibonade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:15:30 by aibonade          #+#    #+#             */
/*   Updated: 2023/11/10 18:24:03 by aibonade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_setnew(char const *s, char *new, size_t len)
{
	size_t	i;

	i = 0;
	while (s[i] && i < len)
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return ;
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			lens;
	char			*new;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		new = malloc(sizeof(char));
		if (!new)
			return (NULL);
		new[0] = '\0';
		return (new);
	}
	lens = ft_strlen(&s[start]);
	if (len < lens)
		new = malloc((len + 1) * sizeof(char));
	else
		new = malloc((lens + 1) * sizeof(char));
	if (!new)
		return (NULL);
	ft_setnew(&s[start], new, len);
	return (new);
}
