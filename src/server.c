/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fszendzi <fszendzi@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 13:55:28 by fszendzi          #+#    #+#             */
/*   Updated: 2023/07/28 13:55:30 by fszendzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serverclient.h"

t_server_state	g_server = {0, 0, {0}, 0};

void	sigusr_handler(int signum, siginfo_t *info, void *context)
{
	(void)context;
	if (signum != SIGUSR1 && signum != SIGUSR2)
	{
		ft_putendl_fd("Not the correct signal", 1);
		return ;
	}
	if (g_server.bit_count == 0)
		g_server.received_char = 0;
	if (g_server.bit_count < 8)
	{
		if (signum == SIGUSR1)
			g_server.received_char |= (1 << g_server.bit_count);
		g_server.bit_count++;
	}
	if (g_server.bit_count == 8)
	{
		g_server.buffer[g_server.buffer_index++] = g_server.received_char;
		if (g_server.received_char == '\0')
		{
			ft_putendl_fd(g_server.buffer, 1);
			g_server.buffer_index = 0;
		}
		g_server.bit_count = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	pid_t				server_pid;
	struct sigaction	sa;

	server_pid = getpid();
	write(1, "Server PID ", 11);
	ft_putnbr_fd(server_pid, 1);
	write(1, "\n", 1);
	sa.sa_sigaction = sigusr_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1 
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_putendl_fd("Error setting up sigaction", 1);
		return (EXIT_FAILURE);
	}
	while (1)
	{
		sleep(1);
	}
	return (0);
}
