/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas < jkarosas@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 20:47:16 by jkarosas          #+#    #+#             */
/*   Updated: 2021/12/27 20:48:04 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_d(va_list *args)
{
	int	a;
	int	count;

	a = va_arg(*args, int);
	count = ft_putnbr(a);
	return (count);
}

int	ft_number_length(long int n)
{
	int		count;
	long	num;

	num = n;
	count = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		count ++;
		num = -num;
	}
	while (num != 0)
	{
		num = num / 10;
		count++;
	}
	return (count);
}

int	ft_putnbr(long int n)
{
	int	count;

	count = ft_number_length(n);
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
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
