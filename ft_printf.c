/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printf.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: yhayyani <yhayyani@student.1337.ma>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/18 01:56:22 by yhayyani         #+#    #+#              */
/*   Updated: 2026/11/21 05:23:21 by yhayyani        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	pf_process(const char *format, va_list *args)
{
	int	i;
	int	count;
	int	ret;

	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			ret = pf_convert(format[i], args);
		}
		else
			ret = pf_putchar(format[i]);
		if (ret == -1)
			return (-1);
		count += ret;
		i++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	if (!format)
		return (-1);
	va_start(args, format);
	count = pf_process(format, &args);
	va_end(args);
	return (count);
}
