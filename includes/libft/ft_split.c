/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibonade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:39:27 by aibonade          #+#    #+#             */
/*   Updated: 2023/11/15 20:14:32 by aibonade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(char const *str, char c)
{
	int	nbw;
	int	i;

	nbw = 0;
	if (!str || !str[0])
		return (0);
	if (str[0] != c)
		nbw++;
	i = 1;
	while (str[i])
	{
		if (str[i - 1] == c && str[i] != c)
			nbw++;
		i++;
	}
	return (nbw);
}

static void	ft_free(char **strs, int index)
{
	while (index >= 0)
	{
		free(strs[index]);
		index--;
	}
	free(strs);
}

static size_t	ft_strlen_c(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	*ft_string(char const *str, char c, size_t *index)
{
	char	*new;
	size_t	len;
	size_t	i;

	len = ft_strlen_c(&str[*index], c);
	new = malloc((len + 1) * sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	while (str[*index] && str[*index] != c)
	{
		new[i] = str[*index];
		i++;
		*index = *index + 1;
	}
	new[i] = '\0';
	return (new);
}

char	**ft_split(char const *s, char c)
{
	char		**strs;
	int			nb_string;
	int			i;
	size_t		j;

	nb_string = ft_countwords(s, c);
	strs = malloc((nb_string + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	i = -1;
	j = 0;
	while (++i < nb_string)
	{
		while (s[j] && s[j] == c)
			j++;
		strs[i] = ft_string(s, c, &j);
		if (strs[i] == NULL)
		{
			ft_free(strs, i - 1);
			return (NULL);
		}
	}
	strs[i] = NULL;
	return (strs);
}
