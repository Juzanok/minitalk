/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas < jkarosas@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 08:26:56 by jkarosas          #+#    #+#             */
/*   Updated: 2022/03/22 21:22:28 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	power(int power)
{
	int	i;
	int	sum;

	i = 1;
	sum = 2;
	if (power == 0)
		return (1);
	while (i < power)
	{
		sum = sum * 2;
		i++;
	}
	return (sum);
}

void	print_str(char **str, int *str_sent, int *i)
{
	if (*str)
	{
		ft_printf("%s\n", *str);
		free(*str);
		*str = 0;
	}
	*i = 0;
	*str_sent = 0;
}
