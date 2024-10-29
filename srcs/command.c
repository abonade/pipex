/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibonade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 19:50:36 by aibonade          #+#    #+#             */
/*   Updated: 2024/09/14 19:50:45 by aibonade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static int	ft_is_not_path(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '/')
			return (0);
		i++;
	}
	return (1);
}

static void	ft_search_cmd(t_cmd *cmd)
{
	char	*tmp;

	cmd->path_cmd = cmd->cmd[0];
	tmp = ft_strrchr(cmd->cmd[0], '/');
	cmd->cmd[0] = ft_strdup(tmp + 1);
}

static void	ft_search_path(t_cmd *cmd, char **path, int psize, t_data *data)
{
	char	*tmp;
	char	*tmp2;
	int		i;

	i = 0;
	tmp2 = NULL;
	while (i < psize)
	{
		tmp = ft_strjoin(path[i], "/");
		if (!tmp)
			ft_error_pars("Join problem.", path, cmd, data);
		tmp2 = ft_strjoin(tmp, cmd->cmd[0]);
		free(tmp);
		if (!tmp2)
			ft_error_pars("Join problem.", path, cmd, data);
		if (access(tmp2, F_OK | X_OK) == 0)
		{
			cmd->path_cmd = tmp2;
			return ;
		}
		free(tmp2);
		i++;
	}
	cmd->path_cmd = NULL;
}

void	ft_create_lst_cmd(int ac, char **av, int i_cmd, t_data *data)
{
	int		psize;
	char	**path;
	t_cmd	*tmp;
	t_list	*new;

	path = NULL;
	path = ft_create_path_tab(data->envp, path, &psize, data);
	while (i_cmd < ac - 1)
	{
		tmp = ft_new_cmd(av, i_cmd);
		if (!tmp)
			ft_error_pars("New command impossible.", path, tmp, data);
		if (ft_is_not_path(tmp->cmd[0]))
			ft_search_path(tmp, path, psize, data);
		else
			ft_search_cmd(tmp);
		new = ft_lstnew(tmp);
		if (!new)
			ft_error_pars("New list element impossible.", path, tmp, data);
		ft_lstadd_back(data->l_cmd, new);
		i_cmd++;
	}
	ft_free_tab(path);
}
