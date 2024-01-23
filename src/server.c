/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsulvac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:57:17 by fsulvac           #+#    #+#             */
/*   Updated: 2024/01/22 15:59:52 by fsulvac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/minitalk.h"
#include <signal.h>
#include <unistd.h>

void	receive(int signal, siginfo_t *info, void *context)
{
	static int	i = 0;
	static char	c = 0;

	(void)info;
	(void)context;
	if (signal == SIGUSR1)
	{
		c |= (1 << i);
		i++;
	}
	else if (signal == SIGUSR2)
		i++;
	if (i == 8)
	{
		ft_printf("%c", c);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;
	sigset_t			signal_mask;

	ft_printf("\033[92mPID: %d\033[0m\n", getpid());
	sigemptyset(&signal_mask);
	sigaddset(&signal_mask, SIGUSR1);
	sigaddset(&signal_mask, SIGUSR2);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_mask = signal_mask;
	sa.sa_handler = NULL;
	sa.sa_sigaction = receive;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	exit(EXIT_SUCCESS);
}
