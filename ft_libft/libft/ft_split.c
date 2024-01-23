/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsulvac <fsulvac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:32:50 by fsulvac           #+#    #+#             */
/*   Updated: 2023/11/19 15:19:58 by fsulvac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static size_t	ft_count_word(const char *str, char c)
{
	size_t	i;
	int		flag;
	size_t	count_word;

	i = 0;
	count_word = 0;
	flag = 1;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			flag = 1;
		else if (str[i] != c && flag == 1)
		{
			count_word++;
			flag = 0;
		}
		i++;
	}
	return (count_word);
}

static void	free_all(char **split, size_t number_of_word)
{
	size_t	i;

	i = 0;
	while (i < number_of_word)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static char	*ft_str(const char *s, size_t start, size_t end)
{
	char	*str;
	size_t	i;

	str = malloc(sizeof(char) * (end - start + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < (end - start))
	{
		str[i] = s[i + start];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	**ft_boucle(char const *s, char **split, char c)
{
	size_t	start;
	size_t	end;
	size_t	i;

	start = 0;
	end = 0;
	i = -1;
	while (++i < ft_count_word(s, c))
	{
		while (s[start] == c && s[start] != '\0')
			start++;
		end = start;
		while (s[end] && s[end] != c)
			end++;
		split[i] = ft_str(s, start, end);
		if (split[i] == NULL)
			return (free_all(split, i), NULL);
		start = end;
	}
	split[i] = 0;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	if (!s)
		return (NULL);
	split = (char **)malloc(sizeof(char *) * (ft_count_word(s, c) + 1));
	if (!split)
		return (NULL);
	split = ft_boucle(s, split, c);
	return (split);
}
