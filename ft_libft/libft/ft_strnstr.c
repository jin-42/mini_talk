/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsulvac <fsulvac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 21:09:55 by fsulvac           #+#    #+#             */
/*   Updated: 2023/11/12 15:46:48 by fsulvac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strnstr(const char *big, const char *small, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	size_small;

	i = 0;
	size_small = ft_strlen(small);
	if (small[0] == '\0')
		return ((char *)big);
	while (i < n && big[i] != '\0' && i + size_small <= n)
	{
		j = 0;
		while (i + j < n && big[i + j] == small[j] && small[j] != '\0')
		{
			j++;
			if (small[j] == '\0')
				return ((char *)(big + i));
		}
		i++;
	}
	return (NULL);
}
