/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibonade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 19:46:04 by aibonade          #+#    #+#             */
/*   Updated: 2024/09/14 19:46:20 by aibonade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putstr_error(char *str_error)
{
	int	str_size;

	str_size = ft_strlen(str_error);
	write(2, "Error\n", 6);
	write(2, str_error, str_size);
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}
