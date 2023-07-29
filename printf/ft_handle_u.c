/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas < jkarosas@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 20:46:41 by jkarosas          #+#    #+#             */
/*   Updated: 2021/12/27 20:47:58 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_u(va_list *args)
{
	unsigned int	a;
	int				count;

	a = va_arg(*args, unsigned int);
	count = ft_putnbr_unsigned(a);
	return (count);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	int	count;

	count = ft_number_length_unsigned(n);
	if (n <= 9)
	{
		ft_putchar(n + '0');
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	return (count);
}

int	ft_number_length_unsigned(unsigned int n)
{
	int				count;
	unsigned int	num;

	num = n;
	count = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num = num / 10;
		count++;
	}
	return (count);
}
