/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas < jkarosas@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 20:46:47 by jkarosas          #+#    #+#             */
/*   Updated: 2021/12/27 20:48:43 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_s(va_list *args)
{
	char	*s;
	int		count;

	count = 0;
	s = va_arg(*args, char *);
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[count])
	{
		ft_putchar(s[count]);
		count++;
	}
	return (count);
}
