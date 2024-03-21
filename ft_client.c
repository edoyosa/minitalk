/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebellini <ebellini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 23:18:27 by ebellini          #+#    #+#             */
/*   Updated: 2024/03/21 09:19:11 by ebellini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	conv_char_bin(char byte, int server_pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (byte & 128)
		{
			if (kill(server_pid, SIGUSR1) == -1)
				exit(EXIT_FAILURE);
		}
		else
		{
			if (kill(server_pid, SIGUSR2) == -1)
				exit(EXIT_FAILURE);
		}
		byte = byte << 1;
		bit++;
		pause();
		usleep(84);
	}
}

void	sent_message(char *message, int server_pid)
{
	while (*message)
	{
		conv_char_bin(*message, server_pid);
		message++;
	}
	conv_char_bin('\0', server_pid);
}

int	main(int argc, char **argv)
{
	struct sigaction	sig_act;

	sig_act.sa_handler = SIG_DFL;
	sigemptyset(&sig_act.sa_mask);
	if (argc == 3)
	{
		sigaction(SIGUSR1, &sig_act, 0);
		sigaction(SIGUSR2, &sig_act, 0);
		sent_message(argv[2], ft_atoi(argv[1]));
		ft_printf("The message has been sent!\n");
	}
	else
		ft_printf("ERROR - check the input: \"./client serverPID message\"\n");
	return (0);
}
