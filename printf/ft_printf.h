/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas < jkarosas@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 20:46:14 by jkarosas          #+#    #+#             */
/*   Updated: 2021/12/27 20:47:54 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *input, ...);
int		ft_print_text(const char *input, va_list *args);
void	ft_putchar(char c);
int		ft_argument_type(const char *input, va_list *args, int i);

int		ft_handle_c(va_list *args);

int		ft_handle_s(va_list *args);

int		ft_handle_d(va_list *args);
int		ft_putnbr(long int n);
int		ft_number_length(long int n);

int		ft_handle_i(va_list *args);

int		ft_handle_percent(void);

int		ft_handle_u(va_list *args);
int		ft_putnbr_unsigned(unsigned int n);
int		ft_number_length_unsigned(unsigned int n);

int		ft_handle_x(va_list *args);

int		ft_handle_big_x(va_list *args);

int		ft_handle_p(va_list *args);
int		ft_hexadecimal(char *base, unsigned long long n, int c);

#endif