/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibonade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 18:43:24 by aibonade          #+#    #+#             */
/*   Updated: 2024/09/14 18:43:56 by aibonade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <sys/wait.h>
# include "libft/libft.h"

typedef struct s_io
{
	int	input;
	int	output;
}	t_io;

typedef struct s_cmd
{
	char	**cmd;
	char	*path_cmd;
}	t_cmd;

typedef struct s_data
{
	char	**envp;
	t_list	**l_cmd;
	t_io	io;
	char	*outfile_name;
	int		cmd_nbr;
}	t_data;

/////////////////////////////////////////
//////////////////UTILS//////////////////
/////////////////////////////////////////
/////			 utils.c			/////
void	ft_close(int fd, t_data *data, int fd_pipe[2]);
void	ft_free_tab(char **str);
void	ft_free_cmd(void *cmd);
void	ft_clean_end(t_data *data);
/////			 error.c			/////
void	ft_error_pars(char *msg, char **path, t_cmd *tmp, t_data *data);
void	ft_error_close(int fd, t_data *data, int fd_pipe[2]);
void	ft_error_exec(char *msg, t_data *data, int fd_pipe[2]);

/////////////////////////////////////////
/////////////////COMMAND/////////////////
/////////////////////////////////////////
/////			command.c			/////
void	ft_create_lst_cmd(int ac, char **av, int i_cmd, t_data *data);
void	ft_check_cmd(t_cmd *cmd, t_data *data, int fd_pipe[2]);
/////		command_utils.c			/////
char	**ft_create_path_tab(char **envp, char **path, int *psize, t_data *d);
t_cmd	*ft_new_cmd(char **av, int i_cmd);

/////////////////////////////////////////
//////////////////PIPEX//////////////////
/////////////////////////////////////////
void	ft_exec(int ac, t_data *data, int i_cmd);

#endif
