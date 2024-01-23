/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsulvac <fsulvac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:59:42 by fsulvac           #+#    #+#             */
/*   Updated: 2023/11/24 13:36:55 by fsulvac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	print_nbr(int nb)
{
	long	nbr;
	long	length;

	nbr = nb;
	length = 0;
	if (nbr < 0)
	{
		nbr *= (-1);
		write(1, "-", 1);
		length += 1;
	}
	if (nbr > 9)
	{
		length += print_nbr(nbr / 10);
	}
	ft_putchar(nbr % 10 + '0');
	length += 1;
	return (length);
}
