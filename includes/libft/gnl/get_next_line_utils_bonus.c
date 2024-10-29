/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibonade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:23:44 by aibonade          #+#    #+#             */
/*   Updated: 2024/01/10 16:08:06 by aibonade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_emptybuffer(char *buff, int i)
{
	while (i <= BUFFER_SIZE)
	{
		buff[i] = '\0';
		i++;
	}
}

void	ft_reset_buffer(char *buffer, int len)
{
	if (len == BUFFER_SIZE)
		ft_emptybuffer(buffer, 0);
	else
	{
		ft_memmove_gnl(buffer, &buffer[len], (BUFFER_SIZE - len));
		ft_emptybuffer(buffer, BUFFER_SIZE - len);
	}
}

void	*ft_memmove_gnl(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*tmpsrc;
	unsigned char	*tmpdest;

	if (n == 0)
		return (dest);
	tmpsrc = (unsigned char *)src;
	tmpdest = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		tmpdest[i] = tmpsrc[i];
		i++;
	}
	return (dest);
}

int	ft_linelen(const char *s)
{
	int	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len] && s[len] != '\n')
		len++;
	if (s[len] == '\n')
		len++;
	return (len);
}

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	char	*new;
	size_t	len1;
	size_t	len2;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_linelen(s1);
	len2 = ft_linelen(s2);
	new = malloc((len1 + len2 + 1) * sizeof(char));
	if (!new)
		return (NULL);
	i = -1;
	while (++i < len1)
		new[i] = s1[i];
	i = 0;
	while (s2[i])
	{
		new[len1 + i] = s2[i];
		i++;
	}
	new[len1 + i] = '\0';
	return (new);
}
