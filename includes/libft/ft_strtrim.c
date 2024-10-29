/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibonade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 19:06:56 by aibonade          #+#    #+#             */
/*   Updated: 2023/11/12 15:31:45 by aibonade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static void	ft_copy(char *new, char const *s, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	size_t	i;
	size_t	j;

	if (!s1 || !set)
		return (NULL);
	if (!s1[0])
	{
		new = malloc(sizeof(char));
		if (!new)
			return (NULL);
		new[0] = '\0';
		return (new);
	}
	i = 0;
	while (s1[i] && ft_isset(s1[i], set))
		i++;
	j = ft_strlen(s1) - 1;
	while (j > i && ft_isset(s1[j], set))
		j--;
	new = malloc((j - i + 2) * sizeof(char));
	if (!new)
		return (NULL);
	ft_copy(new, &s1[i], j - i + 1);
	return (new);
}
