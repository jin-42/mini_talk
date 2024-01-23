/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsulvac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:53:26 by fsulvac           #+#    #+#             */
/*   Updated: 2024/01/22 16:54:56 by fsulvac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/minitalk.h"

void send_bit(pid_t	pid, unsigned char c)
{
	unsigned int		i;

	i = 0;
	while (i < 8)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(50);
		i++;
	}
}

int	check_args(int ac, char **av)
{
	pid_t	pid;
	int		i;

	if (ac != 3 || !av[2][0])
	{
		ft_putstr_fd("\033[91mError arguments, please try again.\nUsage : ./client <pid> <message>\033[0m\n", 2);
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(av[1]);
	if (pid == 0)
	{
		ft_putstr_fd("\033[91mError: PID 0 is reserved for the kernel.\033[0m\n", 2);
		exit(EXIT_FAILURE);
	}
	i = -1;
	while (av[1][++i])
	{
		if (!(ft_isdigit(av[1][i])) || pid < 0)
		{
			ft_putstr_fd("\033[91mError: a PID only has positive decimal numbers.\033[0m\n", 2);
			exit(EXIT_FAILURE);
		}
	}
	return (pid);
}

int		main(int ac, char **av)
{
	pid_t	pid;
	int i;

	pid = check_args(ac, av);
	i = 0;
	while(av[2][i])
		send_bit(pid, av[2][i++]);
	send_bit(pid, '\n');
	exit(EXIT_SUCCESS);
}

