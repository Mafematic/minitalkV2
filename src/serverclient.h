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

# define BUFFER_SIZE 110024

typedef struct s_server_state
{
	int				bit_count;
	unsigned char	received_char;
	char			buffer[BUFFER_SIZE];
	int				buffer_index;
}	t_server_state;

void sigusr_handler(int signum, siginfo_t *info, void *context);
void	send_char_as_signal(int pid, char c);

#endif
