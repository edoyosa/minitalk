/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebellini <ebellini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 23:18:27 by ebellini          #+#    #+#             */
/*   Updated: 2024/03/21 13:45:56 by ebellini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	error_message(void)
{
	ft_printf("ERROR - check the input: \"./client serverPID message\"\n");
	exit(EXIT_FAILURE);
}

void	conv_char_bin(char byte, int server_pid)
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
		usleep(300);
	}
}

void	sent_message(char *message, int server_pid)
{
	int	i;

	i = 0;
	while (message[i])
	{
		conv_char_bin(message[i], server_pid);
		i++;
	}
	conv_char_bin('\0', server_pid);
}

int	main(int argc, char **argv)
{
	int	pid_server;
	char	*message;

	pid_server = 0;
	message = argv[2];
	if (argc == 3)
	{
		pid_server = ft_atoi(argv[1]);
		if (pid_server > 0)
		{
			sent_message(message, pid_server);
			ft_printf("The message has been sent!\n");
		}
		else
			error_message();
	}
	else
		error_message();
	return (0);
}
