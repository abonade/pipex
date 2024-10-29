/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibonade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 19:54:49 by aibonade          #+#    #+#             */
/*   Updated: 2024/09/14 19:54:54 by aibonade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	ft_dup2(int old, int new, int fd_pipe[], t_data *data)
{
	ft_close(new, data, fd_pipe);
	if (dup2(old, new) == -1)
		ft_error_exec("Dup2 error.", data, fd_pipe);
	ft_close(old, data, fd_pipe);
}

static void	ft_open_output_file(t_data *data, int fd_pipe[2])
{
	char	*path;
	int		fd;

	path = data->outfile_name;
	fd = open(path, O_WRONLY | O_TRUNC | O_CREAT, 0664);
	if (fd == -1)
		ft_error_exec("Open output file is impossible.", data, fd_pipe);
	data->io.output = fd;
}

static void	ft_check_access(t_cmd *cmd, t_data *data)
{
	if (!cmd || !cmd->path_cmd || !cmd->cmd)
	{
		ft_clean_end(data);
		ft_putstr_error("Command doesn't exist.");
	}
	if (access(cmd->path_cmd, F_OK | X_OK))
	{
		ft_clean_end(data);
		ft_putstr_error("Command doesn't exist.");
	}
}

static void	ft_child(t_data *data, int fd_pipe[2], t_cmd *cmd, int ac)
{
	ft_dup2(data->io.input, STDIN_FILENO, fd_pipe, data);
	if (data->cmd_nbr <= (ac - 5))
	{
		ft_close(fd_pipe[0], data, fd_pipe);
		ft_dup2(fd_pipe[1], STDOUT_FILENO, fd_pipe, data);
	}
	else
	{
		ft_open_output_file(data, fd_pipe);
		ft_dup2(data->io.output, STDOUT_FILENO, fd_pipe, data);
	}
	ft_check_access(cmd, data);
	execve(cmd->path_cmd, cmd->cmd, data->envp);
	ft_error_exec("Execve error.", data, fd_pipe);
}

void	ft_exec(int ac, t_data *data, int i_cmd)
{
	int		fd_pipe[2];
	pid_t	id;
	t_list	*current_cmd;

	data->cmd_nbr = 0;
	current_cmd = *data->l_cmd;
	while ((i_cmd + data->cmd_nbr) < ac - 1)
	{
		if (((i_cmd + data->cmd_nbr) < ac - 2) && (pipe(fd_pipe) == -1))
			ft_error_exec("Pipe error.", data, fd_pipe);
		id = fork();
		if (id == -1)
			ft_error_exec("Fork error.", data, fd_pipe);
		if (id == 0)
			ft_child(data, fd_pipe, current_cmd->content, ac);
		ft_close(data->io.input, data, fd_pipe);
		if ((i_cmd + data->cmd_nbr) < (ac - 2))
		{
			ft_close(fd_pipe[1], data, fd_pipe);
			data->io.input = fd_pipe[0];
		}
		data->cmd_nbr += 1;
		current_cmd = current_cmd->next;
	}
}
