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
