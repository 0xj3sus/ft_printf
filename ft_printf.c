#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
    va_list args;
    int i;
    int count;
    int ret;

    i = 0;
    count = 0;
    va_start(args, format);
    while (format[i])
    {
        if (format[i] == '%' && format[i + 1] == 'c')
        {
            ret = pf_putchar(va_arg(args, int));
            i++;
        }
        else if (format[i] == '%' && format[i + 1] == 's')
        {
            ret = pf_putstr(va_arg(args, char *));
            i++;
        }
        else if (format[i] == '%' && format[i + 1] == '%')
        {
            ret = ret = pf_putchar('%');
            i++;
        }
        else if (format[i] == '%' &&
                 (format[i + 1] == 'd' || format[i + 1] == 'i'))
        {
            ret = pf_putnbr(va_arg(args, int));
            i++;
        }
        else if (format[i] == '%' && format[i + 1] == 'u')
        {
            ret = pf_putunsigned(va_arg(args, unsigned int));
            i++;
        }
        else
            ret = pf_putchar(format[i]);
        if (ret == -1)
        {
            va_end(args);
            return (-1);
        }
        count += ret;
        i++;
    }
    va_end(args);
    return (count);
}