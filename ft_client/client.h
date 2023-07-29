/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas < jkarosas@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 09:35:28 by jkarosas          #+#    #+#             */
/*   Updated: 2022/03/22 21:07:47 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include "../printf/ft_printf.h"

// client.c
int		main(int argc, char **argv);
void	send_data(int sig);
void	send_int(int pid, int nb);
void	send_bit(int pid, int *bit, char *c, int *i);

// client_utils.c
int		ft_atoi(const char *nptr);
int		ft_strlen(char *str);

#endif