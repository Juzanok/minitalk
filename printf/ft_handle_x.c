/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas < jkarosas@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 20:46:35 by jkarosas          #+#    #+#             */
/*   Updated: 2021/12/27 20:47:58 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_x(va_list *args)
{
	unsigned int	a;
	int				count;

	count = 0;
	a = va_arg(*args, unsigned int);
	count = ft_hexadecimal("0123456789abcdef", a, count);
	return (count);
}

int	ft_handle_big_x(va_list *args)
{
	unsigned int	a;
	int				count;

	count = 0;
	a = va_arg(*args, unsigned int);
	count = ft_hexadecimal("0123456789ABCDEF", a, count);
	return (count);
}
