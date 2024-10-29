/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibonade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 19:52:00 by aibonade          #+#    #+#             */
/*   Updated: 2024/09/14 19:52:05 by aibonade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_error_pars(char *msg, char **path, t_cmd *tmp, t_data *data)
{
	ft_free_tab(path);
	ft_free_cmd(tmp);
	ft_clean_end(data);
	if (close(data->io.input) == -1)
		ft_putstr_error("Close error.");
	ft_putstr_error(msg);
}

void	ft_error_close(int fd, t_data *data, int fd_pipe[2])
{
	if (fd == fd_pipe[0])
		fd_pipe[0] = -1;
	if (fd == fd_pipe[1])
		fd_pipe[1] = -1;
	if (fd_pipe[0] > -1)
	{
		ft_close(fd_pipe[0], data, fd_pipe);
	}
	if (fd_pipe[1] > -1)
	{
		ft_close(fd_pipe[1], data, fd_pipe);
	}
	ft_clean_end(data);
	ft_putstr_error("Close error.");
}

void	ft_error_exec(char *msg, t_data *data, int fd_pipe[2])
{
	if (fd_pipe[0] > -1)
	{
		ft_close(fd_pipe[0], data, fd_pipe);
	}
	if (fd_pipe[1] > -1)
	{
		ft_close(fd_pipe[1], data, fd_pipe);
	}
	ft_clean_end(data);
	ft_putstr_error(msg);
}
