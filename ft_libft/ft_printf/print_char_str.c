/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsulvac <fsulvac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 22:23:51 by fsulvac           #+#    #+#             */
/*   Updated: 2023/11/24 21:07:45 by fsulvac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static size_t	ft_strlen_static(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
	{
		++len;
	}
	return (len);
}

int	print_char(int c)
{
	return (write(1, &c, 1));
}

int	print_str(char *str)
{
	size_t	size_lenght;

	if (!str)
		return (write(1, "(null)", 6));
	size_lenght = ft_strlen_static(str);
	return (write(1, str, size_lenght));
}
