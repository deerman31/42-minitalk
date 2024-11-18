/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:38:49 by ykusano           #+#    #+#             */
/*   Updated: 2023/04/11 17:46:43 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	server_error(int num)
{
	if (num == ARG_ERROR)
		ft_putendl_fd("ERROR: The only argument is server!", STDERR_FILENO);
	else if (num == SIG_ERROR)
		ft_putendl_fd("ERROR: Sigaction failed!", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	handler(int sig, siginfo_t *info, void *context)
{
	static unsigned char	c;
	static int				i;

	(void)context;
	if (sig == SIGUSR1)
		c |= (1 << i);
	i++;
	if (i == 8)
	{
		ft_putchar_fd(c, 1);
		i = 0;
		c = 0;
		kill(info->si_pid, SIGUSR1);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	act;
	int					server_pid;

	(void)argv;
	if (argc != 1)
		server_error(ARG_ERROR);
	server_pid = getpid();
	ft_printf("PID: %d\n", server_pid);
	act.sa_flags = 0;
	act.sa_sigaction = handler;
	sigemptyset(&act.sa_mask);
	while (1)
	{
		if (sigaction(SIGUSR1, &act, NULL) == -1)
			server_error(SIG_ERROR);
		if (sigaction(SIGUSR2, &act, NULL) == -1)
			server_error(SIG_ERROR);
		pause();
	}
	return (0);
}
