/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsulvac <fsulvac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:08:37 by fsulvac           #+#    #+#             */
/*   Updated: 2023/11/24 13:37:35 by fsulvac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	print_unsigned(unsigned int nbr)
{
	int	lenght;

	lenght = 0;
	if (nbr > 9)
	{
		lenght += print_nbr(nbr / 10);
	}
	ft_putchar(nbr % 10 + '0');
	lenght += 1;
	return (lenght);
}
