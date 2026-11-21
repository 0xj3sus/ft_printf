/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printf_decimal.c                               :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: yhayyani <yhayyani@student.1337.ma>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/20 05:55:53 by yhayyani         #+#    #+#              */
/*   Updated: 2026/11/21 05:39:11 by yhayyani        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_putnbr(long n)
{
	int	count;
	int	ret;

	count = 0;
	if (n < 0)
	{
		if (pf_putchar('-') == -1)
			return (-1);
		count++;
		n = -n;
	}
	if (n >= 10)
	{
		ret = pf_putnbr(n / 10);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	if (pf_putchar(n % 10 + '0') == -1)
		return (-1);
	return (count + 1);
}

int	pf_putunsigned(unsigned int n)
{
	int	count;
	int	ret;

	count = 0;
	if (n >= 10)
	{
		ret = pf_putunsigned(n / 10);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	if (pf_putchar(n % 10 + '0') == -1)
		return (-1);
	return (count + 1);
}
