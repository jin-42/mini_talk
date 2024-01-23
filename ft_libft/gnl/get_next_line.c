/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsulvac <fsulvac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 18:56:44 by fsulvac           #+#    #+#             */
/*   Updated: 2023/12/30 18:56:48 by fsulvac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/libft.h"

char	*gnl_strjoin(char *str, char *buffer)
{
	char	*new_line;
	int		i;
	int		j;
	int		buff_size;

	i = 0;
	buff_size = gnl_strlen(buffer);
	new_line = (char *)malloc(sizeof(char) * (buff_size + gnl_strlen(str) + 1));
	if (!new_line)
		return (free(str), NULL);
	while (str[i])
	{
		new_line[i] = str[i];
		i++;
	}
	j = 0;
	free(str);
	while (j < buff_size && buffer[j - 1] != '\n')
		new_line[i++] = buffer[j++];
	new_line[i] = '\0';
	return (new_line);
}

int	find_newline(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		return (i + 1);
	return (0);
}

int	update_gnl(char *new_buff, char *buff, char **str)
{
	int	i;

	i = 0;
	while (buff[i])
	{
		new_buff[i] = buff[i];
		i++;
	}
	new_buff[i] = '\0';
	*str = gnl_strjoin(*str, new_buff);
	if (!*str)
		return (-1);
	return (1);
}

char	*read_line(int fd, char *str, char *buff)
{
	ssize_t	readed;

	readed = 1;
	while (readed > 0)
	{
		readed = read(fd, buff, BUFFER_SIZE);
		if (readed == -1)
			break ;
		buff[readed] = '\0';
		str = gnl_strjoin(str, buff);
		if (!str)
			return (NULL);
		if ((find_newline(str) > 0 || readed == 0) && str[0] != '\0')
			return (str);
	}
	buff[0] = '\0';
	free(str);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*str;

	str = NULL;
	str = str_init(str);
	if (!str)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0 || update_gnl(buffer,
			&buffer[find_newline(buffer)], &str) < 0)
		return (free(str), NULL);
	if (find_newline(str) > 0)
		return (str);
	return (read_line(fd, str, buffer));
}
