/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebellini <ebellini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 23:17:22 by ebellini          #+#    #+#             */
/*   Updated: 2024/03/21 13:30:06 by ebellini         ###   ########.fr       */
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

void	stamp_char(char *c)
{
	ft_printf("%c", *c);
	if (*c == '\0')
	{
		*c = 0;
		ft_printf("\n");
	}
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
	{
		stamp_char(&c);
		bit = 0;
	}
	c <<= 1;
	usleep(200);
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
