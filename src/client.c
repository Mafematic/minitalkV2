/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fszendzi <fszendzi@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 13:55:17 by fszendzi          #+#    #+#             */
/*   Updated: 2023/07/28 13:55:20 by fszendzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serverclient.h"

t_client_state	g_client = {0, 1};

void	interrupt_handler(int signum)
{
	(void)signum;
	g_client.running = 0;
	g_client.acknowledged = 1;
}

void	acknowledgment_handler(int signum)
{
	(void)signum;
	g_client.acknowledged = 1;
}

int	setup_signal(int signal_number, void (*handler)(int))
{
	struct sigaction	sa;

	sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	if (sigaction(signal_number, &sa, NULL) == -1)
	{
		write(1, "Error setting up sigaction\n", 27);
		return (1);
	}
	return (0);
}

void	send_char_as_signal(int pid, char c)
{
	int	ascii_value;
	int	i;

	ascii_value = (int)c;
	i = 0;
	while (i < 8)
	{
		send_signals_of_char(pid, i, ascii_value);
		i++;
		while (!g_client.acknowledged)
			(void)0;
		g_client.acknowledged = 0;
	}
}

int	main(int argc, char **argv)
{
	pid_t				server_pid;
	char				*string_to_send;
	int					i;

	if (argc != 3)
	{
		ft_putendl_fd("Wrong amount of parameters", 1);
		return (EXIT_FAILURE);
	}
	server_pid = ft_atoi(argv[1]);
	string_to_send = argv[2];
	print_parameters(server_pid, string_to_send);
	if (setup_signal(SIGUSR1, acknowledgment_handler) != 0)
		return (EXIT_FAILURE);
	if (setup_signal(SIGINT, interrupt_handler) != 0)
		return (EXIT_FAILURE);
	i = 0;
	while (g_client.running && string_to_send[i] != '\0')
		send_char_as_signal(server_pid, string_to_send[i++]);
	send_char_as_signal(server_pid, '\0');
	sleep(1);
	return (0);
}
