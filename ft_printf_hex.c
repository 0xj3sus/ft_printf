/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printf_hex.c                                   :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: yhayyani <yhayyani@student.1337.ma>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/21 04:12:09 by yhayyani         #+#    #+#              */
/*   Updated: 2026/11/21 07:35:12 by yhayyani        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_puthex(unsigned long n, int upper)
{
	int	count;
	int	ret;

	count = 0;
	if (n >= 16)
	{
		ret = pf_puthex(n / 16, upper);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	if (n % 16 < 10)
		ret = pf_putchar(n % 16 + '0');
	else if (upper)
		ret = pf_putchar(n % 16 - 10 + 'A');
	else
		ret = pf_putchar(n % 16 - 10 + 'a');
	if (ret == -1)
		return (-1);
	return (count + ret);
}

int	pf_putpointer(void *ptr)
{
	int	count;
	int	ret;

	if (!ptr)
		return (pf_putstr("(nil)"));
	count = pf_putstr("0x");
	if (count == -1)
		return (-1);
	ret = pf_puthex((unsigned long) ptr, 0);
	if (ret == -1)
		return (-1);
	count += ret;
	return (count);
}
