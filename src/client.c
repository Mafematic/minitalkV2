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
#include <stdbool.h>

volatile sig_atomic_t g_acknowledged = 0;

void acknowledgment_handler(int signum)
{
	(void)signum;
	g_acknowledged = 1;
}

void send_char_as_signal(int pid, char c)
{
	int ascii_value;
	int i;

	ascii_value = (int)c;
	i = 0;
	while (i < 8)
	{
		if (ascii_value & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		while (!g_acknowledged); // wait for acknowledgment
			//usleep(10);
		g_acknowledged = 0;
		//usleep(10);
	}
}

int main(int argc, char **argv)
{
	pid_t server_pid;
	char *string_to_send;
	int i;
	struct sigaction sa;

	if (argc != 3)
	{
		write(1, "Wrong amount of parameters", 26);
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	write(1, "Server PID: ", 12);
	ft_putnbr_fd(server_pid, 1);
	write(1, "\n", 1);
	string_to_send = argv[2];
	write(1, "String: ", 8);
	ft_putstr_fd(string_to_send, 1);
	write(1, "\n", 1);
	sa.sa_handler = acknowledgment_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		write(1, "Error setting up sigaction\n", 27);
		return (1);
	}
	i = 0;
	while (string_to_send[i] != '\0')
	{
		send_char_as_signal(server_pid, string_to_send[i++]);
	}
	send_char_as_signal(server_pid, '\0');
	sleep(1);
	return (0);
}
