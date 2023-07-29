/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas < jkarosas@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 20:47:21 by jkarosas          #+#    #+#             */
/*   Updated: 2021/12/27 20:48:43 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_c(va_list *args)
{
	char	c;

	c = va_arg(*args, int);
	ft_putchar(c);
	return (1);
}
