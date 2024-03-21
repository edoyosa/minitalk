/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebellini <ebellini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 23:17:22 by ebellini          #+#    #+#             */
/*   Updated: 2024/03/21 09:23:01 by ebellini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static int	pid_client;
	static int	bit;
	static char	c;

	(void)context;
	pid_client = 0;
	if (!pid_client)
		pid_client = info->si_pid;
	if (pid_client != info->si_pid)
	{
		pid_client = info->si_pid;
		bit = 0;
		c = 0;
	}
	if (sig == SIGUSR1)
		c = c | sig;
	if (++bit == 8)
	{
		ft_printf("%c", c);
		if (c == '\0')
			c = 0;
		bit = 0;
	}
	c <<= 1;
	usleep(84);
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
	return (0);
}
