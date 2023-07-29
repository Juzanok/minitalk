/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas < jkarosas@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 21:52:07 by jkarosas          #+#    #+#             */
/*   Updated: 2022/03/22 21:22:37 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	g_pid;

void	get_pid(int *bit, int sig)
{
	static int	client_pid = 0;

	if (sig == SIGUSR2)
		client_pid = client_pid + power(*bit);
	if (*bit == 31)
	{
		g_pid = client_pid;
		client_pid = 0;
		*bit = 0;
		return ;
	}
	(*bit)++;
}

void	get_len(int *bit, char **str, int *str_size, int sig)
{
	static int	len = 0;

	if (sig == SIGUSR2)
		len = len + power(*bit);
	if (*bit == 31)
	{
		*str_size = len;
		*str = (char *)malloc(sizeof(char) * (len + 1));
		*bit = 0;
		len = 0;
		return ;
	}
	(*bit)++;
}

void	get_char(int sig, int *bit, char **str, int *str_size)
{
	static int	c = 0;
	static int	i = 0;

	if (sig == SIGUSR2)
		c = c + power(*bit);
	if (*bit == 7)
	{
		*(*str + i) = c;
		i++;
		*bit = 0;
		if (c == 0)
		{
			print_str(str, str_size, &i);
			kill(g_pid, SIGUSR2);
			g_pid = 0;
			return ;
		}
		c = 0;
		kill(g_pid, SIGUSR1);
		return ;
	}
	(*bit)++;
	kill(g_pid, SIGUSR1);
}

void	get_data(int sig)
{
	static char	*str = 0;
	static int	str_size = 0;
	static int	bit = 0;

	if (!g_pid)
		get_pid(&bit, sig);
	else if (!str_size)
		get_len(&bit, &str, &str_size, sig);
	else
		get_char(sig, &bit, &str, &str_size);
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("Server PID: %i\n", pid);
	signal(SIGUSR1, get_data);
	signal(SIGUSR2, get_data);
	while (1)
		pause();
	return (0);
}
