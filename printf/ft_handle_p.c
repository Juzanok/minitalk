/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas < jkarosas@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 20:47:01 by jkarosas          #+#    #+#             */
/*   Updated: 2021/12/27 20:48:43 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_p(va_list *args)
{
	unsigned long long	a;
	int					count;

	a = va_arg(*args, unsigned long long);
	if (a == 0)
	{
		write (1, "0x0", 3);
		return (3);
	}
	write (1, "0x", 2);
	count = 2;
	count = ft_hexadecimal("0123456789abcdef", a, count);
	return (count);
}

int	ft_hexadecimal(char *base, unsigned long long n, int c)
{
	static int	count;
	double		remainder;
	int			i;

	count = c;
	remainder = (double)n / 16;
	i = (remainder - n / 16) * 16;
	if (n / 16 != 0)
	{
		ft_hexadecimal(base, n / 16, count);
		ft_hexadecimal(base, n % 16, count);
	}
	if (n < 16)
	{
		ft_putchar(base[i]);
		count++;
	}
	return (count);
}
