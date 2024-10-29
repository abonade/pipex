/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibonade <aibonade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 13:32:11 by abonade-          #+#    #+#             */
/*   Updated: 2024/09/04 18:59:34 by aibonade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_open_input_file(char *path, int *input_fd, t_data *data)
{
	if (access(path, F_OK | R_OK) == 0)
		*input_fd = open(path, O_RDONLY);
	else
	{
		ft_clean_end(data);
		ft_putstr_error("Access denied for input file.");
	}
	if (*input_fd == -1)
	{
		ft_clean_end(data);
		ft_putstr_error("Open input file is impossible.");
	}
}

void	ft_init_main(t_data *data, int *i_cmd, char **envp, char *outfile_name)
{
	data->envp = envp;
	data->io.input = STDIN_FILENO;
	data->io.output = STDOUT_FILENO;
	data->l_cmd = malloc(sizeof(t_list *));
	if (!data->l_cmd)
		ft_putstr_error("Malloc error.");
	*data->l_cmd = NULL;
	data->outfile_name = outfile_name;
	*i_cmd = 2;
}

void	ft_check_output(char *path, t_data *data)
{
	if (access(path, F_OK) == 0)
	{
		if (access(path, W_OK) != 0)
		{
			ft_clean_end(data);
			ft_putstr_error("Output file is unwritable.");
		}
	}
}

int	main(int ac, char **av, char **envp)
{
	int		i_cmd;
	t_data	data;

	ft_init_main(&data, &i_cmd, envp, av[ac - 1]);
	if (ac != 5 || !envp || !envp[0])
	{
		ft_clean_end(&data);
		ft_putstr_error("Bad arguments !");
	}
	ft_open_input_file(av[1], &data.io.input, &data);
	ft_check_output(av[ac - 1], &data);
	ft_create_lst_cmd(ac, av, i_cmd, &data);
	ft_exec(ac, &data, i_cmd);
	while (wait(NULL) > 0)
		;
	ft_clean_end(&data);
	return (0);
}
