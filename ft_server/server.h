/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas < jkarosas@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 08:22:39 by jkarosas          #+#    #+#             */
/*   Updated: 2022/03/22 21:22:25 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include "../printf/ft_printf.h"

// server.c
int		main(void);
void	get_data(int sig);
void	get_char(int sig, int *bit, char **str, int *str_size);
void	get_len(int *bit, char **str, int *str_size, int sig);
void	get_pid(int *bit, int sig);

// server_utils.c
int		power(int power);
void	print_str(char **str, int *str_sent, int *i);

#endif