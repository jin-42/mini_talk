/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsulvac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:53:26 by fsulvac           #+#    #+#             */
/*   Updated: 2024/01/23 14:47:29 by fsulvac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	g_bit_handler;

void	validation_server(int signal)
{
	if (signal == SIGUSR2)
	{
		ft_printf("Message sent and received.\n");
		exit(EXIT_SUCCESS);
	}
	else if (signal == SIGUSR1)
		g_bit_handler = 1;
}

void	send_bit(pid_t pid, unsigned char c)
{
	unsigned int	i;

	i = 0;
	while (i < 8)
	{
		g_bit_handler = 0;
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (g_bit_handler != 1)
			usleep(100);
		i++;
	}
}

int	check_args(int ac, char **av)
{
	pid_t	pid;
	int		i;

	if (ac != 3 || !av[2][0])
	{
		ft_putstr_fd("Usage : ./client <pid> <message>\n", 2);
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(av[1]);
	if (pid == 0)
	{
		ft_putstr_fd("Error: PID 0 is reserved for the kernel.\n", 2);
		exit(EXIT_FAILURE);
	}
	i = -1;
	while (av[1][++i])
	{
		if (!(ft_isdigit(av[1][i])) || pid < 0)
		{
			ft_putstr_fd("Error: a PID only has positive decimal numbers.\n",
				2);
			exit(EXIT_FAILURE);
		}
	}
	return (pid);
}

int	main(int ac, char **av)
{
	pid_t	pid;
	int		i;

	pid = check_args(ac, av);
	i = 0;
	signal(SIGUSR1, validation_server);
	signal(SIGUSR2, validation_server);
	while (av[2][i])
		send_bit(pid, av[2][i++]);
	send_bit(pid, 0);
	send_bit(pid, '\n');
	exit(EXIT_SUCCESS);
}
