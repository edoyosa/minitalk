/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebellini <ebellini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 23:17:22 by ebellini          #+#    #+#             */
/*   Updated: 2024/08/08 15:58:10 by ebellini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	start_banner(int pid)
{
	ft_printf("\n\t███╗   ███╗██╗███╗   ██╗██╗████████╗ █████╗ ██╗     ██╗██╗\
					\n");
	ft_printf("\t██╔████╔██║██║██╔██╗ ██║██║   ██║   ███████║██║     █████╔╝\
						 \n");
	ft_printf("\t██║╚██╔╝██║██║██║╚██╗██║██║   ██║   ██╔══██║██║     ██╔═██╗\
							 \n");
	ft_printf("\t██║ ╚═╝ ██║██║██║ ╚████║██║   ██║   ██║  ██║███████╗██║  ██╗\
								\n");
	ft_printf("\t╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝   ╚═╝   ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝\
									\n");
	ft_printf("\n\t\tPID: %d\t\t\tBy: ebellini\n", pid);
	ft_printf("\t⊱ ────────────────────── {.⋅ ✯ ⋅.} ─────────────────────── ⊰\
											\n\n");
}

void	stamp_char(char *c, int *bit, int *pid_client)
{
	ft_printf("%c", *c);
	if (*c == '\0')
	{
		ft_printf("\n PID CLIENT: %d \n", *pid_client);
		if (kill(*pid_client, SIGUSR1) == -1)
			exit(EXIT_FAILURE);
	}
	else
		*bit = 0;
}

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static int	pid_client;
	static int	bit;
	static char	c;

	(void)context;
	if (!pid_client)
		pid_client = info->si_pid;
	if (pid_client != info->si_pid)
	{
		pid_client = info->si_pid;
		bit = 0;
		c = 0;
	}
	c |= (sig == SIGUSR1);
	if (++bit == 8)
		stamp_char(&c, &bit, &pid_client);
	c <<= 1;
	usleep(100);
	if (kill(pid_client, SIGUSR2) == -1)
		exit(EXIT_FAILURE);
}

int	main(void)
{
	int					pid;
	struct sigaction	sig_act;

	pid = getpid();
	start_banner(pid);
	sig_act.sa_sigaction = &handle_signal;
	sigemptyset(&sig_act.sa_mask);
	sig_act.sa_flags = SA_SIGINFO;
	while (1)
	{
		sigaction(SIGUSR1, &sig_act, 0);
		sigaction(SIGUSR2, &sig_act, 0);
		pause();
	}
}
