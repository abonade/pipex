/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibonade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 15:20:35 by aibonade          #+#    #+#             */
/*   Updated: 2024/09/15 15:20:38 by aibonade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	**ft_create_path_tab(char **envp, char **path, int *psize, t_data *d)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
		{
			path = ft_split(ft_strchr(envp[i], '/'), ':');
			if (!path)
				ft_error_pars("Split path doesn't work.", path, NULL, d);
		}
		i++;
	}
	if (!path)
		ft_error_pars("There's no PATH in env.", path, NULL, d);
	*psize = 0;
	while (path[*psize])
		*psize += 1;
	return (path);
}

t_cmd	*ft_new_cmd(char **av, int i_cmd)
{
	t_cmd	*tmp;

	tmp = malloc(sizeof(t_cmd));
	if (!tmp)
		return (NULL);
	tmp->cmd = NULL;
	tmp->path_cmd = NULL;
	tmp->cmd = ft_split(av[i_cmd], ' ');
	if (!tmp->cmd)
	{
		free(tmp);
		return (NULL);
	}
	return (tmp);
}
