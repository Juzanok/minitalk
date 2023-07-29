/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas < jkarosas@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 20:47:08 by jkarosas          #+#    #+#             */
/*   Updated: 2021/12/27 20:48:04 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_i(va_list *args)
{
	int	a;
	int	count;

	a = va_arg(*args, int);
	count = ft_putnbr(a);
	return (count);
}
