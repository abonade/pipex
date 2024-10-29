/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibonade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:55:27 by aibonade          #+#    #+#             */
/*   Updated: 2023/11/15 20:18:25 by aibonade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(long int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
	{
		n = -n;
		len++;
	}
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	ft_change(long int n, char *s, size_t i)
{
	s[i] = '\0';
	i--;
	while (n > 9)
	{
		s[i] = n % 10 + 48;
		i--;
		n = n / 10;
	}
	s[i] = n % 10 + 48;
}

char	*ft_itoa(int n)
{
	char		*str;
	size_t		len;
	long int	nbr;

	nbr = n;
	len = ft_len(n);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	ft_change(nbr, str, len);
	return (str);
}
