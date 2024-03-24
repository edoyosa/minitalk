/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebellini <ebellini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 23:18:27 by ebellini          #+#    #+#             */
/*   Updated: 2024/03/24 13:24:26 by ebellini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	error_message(void)
{
	ft_printf("ERROR - check the input: \"./client serverPID message\"\n");
	exit(EXIT_FAILURE);
}

void	conversion(unsigned char byte, int server_pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (byte & 128)
		{
			if (kill(server_pid, SIGUSR1) == -1)
				error_message();
		}
		else
		{
			if (kill(server_pid, SIGUSR2) == -1)
				error_message();
		}
		byte = byte << 1;
		bit++;
		pause();
		usleep(100);
	}
}

void	sent_message(char *message, int server_pid)
{
	int	i;

	i = 0;
	while (message[i])
	{
		conversion(message[i], server_pid);
		i++;
	}
	conversion('\0', server_pid);
}

void	handle_signal(int sig)
{
	if (sig == SIGUSR1)
	{
		ft_printf("The message has been sent without errors!\n");
		exit(EXIT_SUCCESS);
	}
}

int	main(int argc, char **argv)
{
	int					pid_server;
	char				*message;
	struct sigaction	sig_act;

	pid_server = 0;
	message = argv[2];
	if (argc == 3)
	{
		pid_server = ft_atoi(argv[1]);
		if (pid_server > 0)
		{
			sig_act.sa_handler = &handle_signal;
			sigemptyset(&sig_act.sa_mask);
			ft_printf("PID CLIENT: %d\n", getpid());
			sigaction(SIGUSR1, &sig_act, 0);
			sigaction(SIGUSR2, &sig_act, 0);
			sent_message(message, pid_server);
		}
		else
			error_message();
	}
	else
		error_message();
	return (0);
}
