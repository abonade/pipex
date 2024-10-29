/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibonade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:36:44 by aibonade          #+#    #+#             */
/*   Updated: 2023/12/03 03:34:56 by aibonade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42 
# endif
# include "stdlib.h"
# include "unistd.h"

char	*get_next_line(int fd);
void	ft_reset_buffer(char *buffer, int len);
int		ft_linelen(const char *s);
char	*ft_strjoin_gnl(char const *s1, char const *s2);
void	*ft_memmove_gnl(void *dest, const void *src, size_t n);
char	*ft_get_line2(char *line, char *buffer, int fd);

#endif
