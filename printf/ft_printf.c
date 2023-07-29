/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas < jkarosas@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 20:46:26 by jkarosas          #+#    #+#             */
/*   Updated: 2021/12/27 20:47:56 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_argument_type(const char *input, va_list *args, int i)
{
	int	count;

	count = 0;
	if (input[i] == 'c')
		count += ft_handle_c(args);
	else if (input[i] == 's')
		count += ft_handle_s(args);
	else if (input[i] == 'p')
		count += ft_handle_p(args);
	else if (input[i] == 'd')
		count += ft_handle_d(args);
	else if (input[i] == 'i')
		count += ft_handle_i(args);
	else if (input[i] == 'u')
		count += ft_handle_u(args);
	else if (input[i] == 'x')
		count += ft_handle_x(args);
	else if (input[i] == 'X')
		count += ft_handle_big_x(args);
	else if (input[i] == '%')
		count += ft_handle_percent();
	return (count);
}

int	ft_print_text(const char *input, va_list *args)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (input[i])
	{
		if (input[i] == '%')
		{
			count += ft_argument_type(input, args, i + 1);
			i++;
		}
		else if (input[i])
		{
			ft_putchar(input[i]);
			count++;
		}
		i++;
	}
	return (count);
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		char_count;

	va_start(args, input);
	char_count = ft_print_text(input, &args);
	va_end(args);
	return (char_count);
}
