/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printf.h                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: yhayyani <yhayyani@student.1337.ma>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/18 01:22:05 by yhayyani         #+#    #+#              */
/*   Updated: 2026/11/21 05:26:21 by yhayyani        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	pf_putchar(char c);
int	pf_putstr(char *s);
int	pf_putunsigned(unsigned int n);
int	pf_putnbr(long n);
int	pf_puthex(unsigned long n, int upper);
int	pf_putpointer(void *ptr);
int	pf_convert(char c, va_list *args);

#endif
