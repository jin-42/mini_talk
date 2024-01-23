/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsulvac <fsulvac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:33:57 by fsulvac           #+#    #+#             */
/*   Updated: 2023/11/25 14:10:14 by fsulvac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static size_t	ft_putnbr_hexa_helper(unsigned long long nb, const char *base)
{
	size_t	size;
	size_t	result;

	size = 16;
	result = 0;
	if (nb >= size)
	{
		result += ft_putnbr_hexa_helper(nb / size, base);
		result += write(1, &base[nb % size], 1);
	}
	else
		result += write(1, &base[nb % size], 1);
	return (result);
}

static int	ft_putnbr_hexa(unsigned long long nb)
{
	int			result;
	const char	*base = "0123456789abcdef";

	result = ft_putnbr_hexa_helper(nb, base);
	return (result);
}

int	print_ptr(void *ptr)
{
	int	length;

	if (!ptr)
		return (write(1, "(nil)", 5));
	length = write(1, "0x", 2);
	length += ft_putnbr_hexa((unsigned long long)ptr);
	return (length);
}
