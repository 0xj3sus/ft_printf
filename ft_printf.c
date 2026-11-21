#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
    va_list args;
    int i;
    int count;

    i = 0;
    count = 0;
    va_start(args, format);

    while (format[i])
    {
        if (format[i] == '%' && format[i + 1] == 'c')
        {
            if (pf_putchar(va_arg(args, int)) == -1)
            {
                va_end(args);
                return (-1);
            }

            i++;
        }
        else if (format[i] == '%' && format[i + 1] == 's')
        {
            if (pf_putstr(va_arg(args, char*)) == -1)
            {
                va_end(args);
                return (-1);
            }

            i++;
        }

        else if ( pf_putchar(format[i]) == -1)
        {
            va_end(args);
            return (-1);
        }
        i++;
        count++;
    }

    va_end(args);
    return (count);
}
