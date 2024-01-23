/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsulvac <fsulvac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 22:27:08 by fsulvac           #+#    #+#             */
/*   Updated: 2023/11/18 23:47:54 by fsulvac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static size_t	intlen(int n)
{
	size_t	i;

	i = 1;
	n /= 10;
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*s;
	size_t		len;
	long int	nb;

	nb = n;
	len = intlen(n);
	if (n < 0)
	{
		nb = -nb;
		len++;
	}
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	s[len] = 0;
	while (len--)
	{
		s[len] = nb % 10 + '0';
		nb = nb / 10;
	}
	if (n < 0)
		s[0] = '-';
	return (s);
}
