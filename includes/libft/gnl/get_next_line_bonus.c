/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibonade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:36:29 by aibonade          #+#    #+#             */
/*   Updated: 2024/01/10 16:07:44 by aibonade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_get_line(char *buffer, int len)
{
	char	*line;
	int		i;

	line = malloc((len + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_continue(char *line, char *buffer, int fd, int len)
{
	ft_reset_buffer(buffer, len);
	return (ft_get_line2(line, buffer, fd));
}

char	*ft_get_line2(char	*line, char *buffer, int fd)
{
	int		rd_value;
	char	*linetmp;
	char	*new_line;
	int		len_tmp;

	rd_value = read(fd, buffer, BUFFER_SIZE);
	if (rd_value == 0)
		return (line);
	if (rd_value < 0)
	{
		free(line);
		return (NULL);
	}
	len_tmp = ft_linelen(buffer);
	linetmp = ft_get_line(buffer, len_tmp);
	new_line = ft_strjoin_gnl(line, linetmp);
	free(line);
	free(linetmp);
	if (!new_line)
		return (NULL);
	if (buffer[len_tmp - 1] != '\n' && rd_value == BUFFER_SIZE)
		new_line = ft_continue(new_line, buffer, fd, len_tmp);
	else
		ft_reset_buffer(buffer, len_tmp);
	return (new_line);
}

char	*get_next_line(int fd)
{
	char		*line;
	int			len;
	static char	buffer[1000][BUFFER_SIZE + 1];
	int			rd_value;

	if (fd < 0 || fd >= 1000 || BUFFER_SIZE <= 0)
		return (NULL);
	rd_value = BUFFER_SIZE;
	if (!buffer[fd][0])
	{
		rd_value = read(fd, buffer[fd], BUFFER_SIZE);
		if (rd_value <= 0)
			return (NULL);
	}
	len = ft_linelen(buffer[fd]);
	line = ft_get_line(buffer[fd], len);
	if (!line)
		return (NULL);
	if (buffer[fd][len - 1] != '\n' && rd_value == BUFFER_SIZE)
		line = ft_continue(line, buffer[fd], fd, len);
	else
		ft_reset_buffer(buffer[fd], len);
	return (line);
}
