/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibonade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 19:47:52 by aibonade          #+#    #+#             */
/*   Updated: 2024/09/14 19:47:56 by aibonade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_close(int fd, t_data *data, int fd_pipe[2])
{
	if (close(fd) == -1)
		ft_error_close(fd, data, fd_pipe);
}

void	ft_free_tab(char **str)
{
	size_t	i;

	if (str)
	{
		i = 0;
		while (str[i])
		{
			free(str[i]);
			i++;
		}
		free(str);
	}
}

void	ft_free_cmd(void *cmd)
{
	if (cmd)
	{
		if (((t_cmd *)cmd)->cmd)
			ft_free_tab(((t_cmd *)cmd)->cmd);
		if (((t_cmd *)cmd)->path_cmd)
			free(((t_cmd *)cmd)->path_cmd);
		free(cmd);
	}
}

void	ft_clean_end(t_data *data)
{
	if (data->l_cmd)
	{
		ft_lstclear(data->l_cmd, &ft_free_cmd);
		free(data->l_cmd);
	}
}
