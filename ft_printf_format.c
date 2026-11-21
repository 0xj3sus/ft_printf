/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printf_format.c                                :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: yhayyani <yhayyani@student.1337.ma>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/20 03:30:20 by yhayyani         #+#    #+#              */
/*   Updated: 2026/11/21 04:56:36 by yhayyani        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_convert(char c, va_list *args)
{
	if (c == 'c')
		return (pf_putchar(va_arg(*args, int)));
	if (c == 's')
		return (pf_putstr(va_arg(*args, char *)));
	if (c == 'p')
		return (pf_putpointer(va_arg(*args, void *)));
	if (c == 'd' || c == 'i')
		return (pf_putnbr(va_arg(*args, int)));
	if (c == 'u')
		return (pf_putunsigned(va_arg(*args, unsigned int)));
	if (c == 'x')
		return (pf_puthex(va_arg(*args, unsigned int), 0));
	if (c == 'X')
		return (pf_puthex(va_arg(*args, unsigned int), 1));
	if (c == '%')
		return (pf_putchar('%'));
	return (-1);
}
