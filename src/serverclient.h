/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serverclient.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fszendzi <fszendzi@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 13:55:52 by fszendzi          #+#    #+#             */
/*   Updated: 2023/07/28 13:55:56 by fszendzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVERCLIENT_H
# define SERVERCLIENT_H

# include "../Libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <sys/types.h>

# define BUFFER_SIZE 22222

typedef struct s_server_state
{
	int				bit_count;
	unsigned char	received_char;
	char			buffer[BUFFER_SIZE];
	int				buffer_index;
}	t_server_state;

typedef struct s_client_state {
	volatile sig_atomic_t	acknowledged;
	volatile sig_atomic_t	running;
}	t_client_state;

void	print_parameters(pid_t server_pid, char *string_to_send);
int		setup_signal(int signal_number, void (*handler)(int));
void	sigusr_handler(int signum, siginfo_t *info, void *context);
void	interrupt_handler(int signum);
void	acknowledgment_handler(int signum);
void	send_signals_of_char(int pid, int i, int ascii_value);
void	send_char_as_signal(int pid, char c);

#endif
