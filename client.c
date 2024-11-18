/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:25:57 by ykusano           #+#    #+#             */
/*   Updated: 2023/04/11 20:07:16 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	client_error(int num)
{
	if (num == ARG_ERROR)
		ft_putendl_fd("ERROR: Incorrect number of arguments!", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	binaly_send(int server_pid, unsigned char c)
{
	size_t		i;

	i = 0;
	while (i < 8)
	{
		if (c % 2 == 1)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(250);
		c /= 2;
		i++;
	}
}

void	handler(int sig)
{
	if (sig == SIGUSR1)
		return ;
}

int	main(int argc, char **argv)
{
	int				server_pid;
	size_t			i;

	if (argc != 3)
		client_error(ARG_ERROR);
	server_pid = ft_atoi(argv[1]);
	i = 0;
	while (argv[2][i])
	{
		signal(SIGUSR1, handler);
		binaly_send(server_pid, (unsigned char)argv[2][i]);
		i++;
	}
	return (0);
}
