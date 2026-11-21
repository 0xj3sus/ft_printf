/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printf_utils.c                                 :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: yhayyani <yhayyani@student.1337.ma>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/19 05:40:24 by yhayyani         #+#    #+#              */
/*   Updated: 2026/11/21 05:40:27 by yhayyani        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_putchar(char c)
{
	if (write(1, &c, 1) == 1)
		return (1);
	return (-1);
}

int	pf_putstr(char *s)
{
	int	i;

	if (!s)
		s = "(null)";
	i = 0;
	while (s[i])
	{
		if (pf_putchar(s[i]) == -1)
			return (-1);
		i++;
	}
	return (i);
}
