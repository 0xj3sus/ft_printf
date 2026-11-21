#include "ft_printf.h"

int pf_putchar(char c)
{
    if (write(1, &c, 1) == 1)
        return (1);
    return (-1);
}

int pf_putstr(char *s)
{
    if (!s)
        s = "(null)";
    int i;
    i = 0;
    while (s[i])
    {
        if (pf_putchar(s[i]) == -1)
            return (-1);
        i++;
    }
    return (i);
}
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