/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fszendzi <fszendzi@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 18:21:56 by fszendzi          #+#    #+#             */
/*   Updated: 2023/07/31 18:21:58 by fszendzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serverclient.h"

void	send_signals_of_char(int pid, int i, int ascii_value)
{
	if (ascii_value & (1 << i))
	{
		if (kill(pid, SIGUSR1) == -1)
		{
			ft_putendl_fd("Error sending signal to server.", 1);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (kill(pid, SIGUSR2) == -1) 
		{
			ft_putendl_fd("Error sending signal to server", 1);
			exit(EXIT_FAILURE);
		}
	}
}

void	print_parameters(pid_t server_pid, char *string_to_send)
{
	write(1, "Server PID: ", 12);
	ft_putnbr_fd(server_pid, 1);
	write(1, "\n", 1);
	write(1, "String: ", 8);
	ft_putendl_fd(string_to_send, 1);
}
