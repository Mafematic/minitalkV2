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

void sigusr_handler(int signum, siginfo_t *info, void *context)
{
	(void)context;
	if (signum != SIGUSR1 && signum != SIGUSR2)
	{
		write(1, "Not the correct signal\n", 23);
		return;
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
			ft_putstr_fd(g_server.buffer, 1);
			write(1, "\n", 1);
			g_server.buffer_index = 0;
		}
		g_server.bit_count = 0;
	}
	kill(info->si_pid, SIGUSR1); // send acknowledgement signal back to client
}

int main(void)
{
	pid_t server_pid;
	struct sigaction sa;

	server_pid = getpid();
	write(1, "Server PID ", 11);
	ft_putnbr_fd(server_pid, 1);
	write(1, "\n", 1);
	sa.sa_sigaction = sigusr_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO; // enable the SA_SIGINFO flag
	if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		write(1, "Error setting up sigaction\n", 27);
		return (1);
	}
	while (1)
	{
		sleep(1);
	}
	return (0);
}
