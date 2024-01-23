/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsulvac <fsulvac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:48:38 by fsulvac           #+#    #+#             */
/*   Updated: 2023/11/23 12:16:43 by fsulvac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*arr;

	if (INT_MAX / nmemb > size)
		return (NULL);
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	arr = (void *)malloc(size * nmemb);
	if (!arr)
		return (NULL);
	ft_bzero(arr, size * nmemb);
	return (arr);
}
