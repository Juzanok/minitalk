/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas < jkarosas@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 21:52:04 by jkarosas          #+#    #+#             */
/*   Updated: 2022/03/22 21:27:49 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

char	*g_str;

void	send_data(int sig)
{
	static int	pid = 0;
	static int	bit = 0;
	static int	i = 0;
	static char	c = 0;

	if (sig != SIGUSR1 && sig != SIGUSR2)
	{
		pid = sig;
		c = g_str[0];
		send_bit(pid, &bit, &c, &i);
	}
	else if (sig == SIGUSR1)
		send_bit(pid, &bit, &c, &i);
	else if (sig == SIGUSR2)
	{
		ft_printf("Your message was printed\n");
		exit(0);
	}
}

void	send_bit(int pid, int *bit, char *c, int *i)
{
	if (*bit == 8)
	{
		(*i)++;
		(*bit) = 0;
		(*c) = g_str[(*i)];
	}
	if ((*bit) < 8)
	{
		if (*c & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		*c = *c >> 1;
		(*bit)++;
	}
}

void	send_int(int pid, int nb)
{
	int	i;

	i = -1;
	while (++i < 32)
	{
		if (nb & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		nb = nb >> 1;
		usleep(1000);
	}
}

int	main(int argc, char **argv)
{
	int		server_pid;
	int		client_pid;

	if (argc != 3 || !ft_strlen(argv[2]))
	{
		ft_printf("Usage: ./client [server_pid] [str_to_send]\n");
		return (1);
	}
	signal(SIGUSR1, send_data);
	signal(SIGUSR2, send_data);
	g_str = argv[2];
	server_pid = ft_atoi(argv[1]);
	client_pid = getpid();
	send_int(server_pid, client_pid);
	send_int(server_pid, ft_strlen(argv[2]));
	send_data(server_pid);
	while (1)
		pause();
	return (0);
}
