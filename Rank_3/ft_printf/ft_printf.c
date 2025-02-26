/*
Assignment name  : ft_printf  
Expected files   : ft_printf.c  
Allowed functions: malloc, free, write, va_start, va_arg, va_copy, va_end  

--------------------------------------------------------------------------------

Write a function named `ft_printf` that will mimic the real printf but
it will manage only the following conversions: s,d and x.

Your function must be declared as follows:

int ft_printf(const char *, ... );

Before you start we advise you to read the `man 3 printf` and the `man va_arg`.
To test your program compare your results with the true printf.

Exemples of the function output:

call: ft_printf("%s\n", "toto");
out: toto$

call: ft_printf("Magic %s is %d", "number", 42);
out: Magic number is 42%

call: ft_printf("Hexadecimal for %d is %x\n", 42, 42);
out: Hexadecimal for 42 is 2a$

Obs: Your function must not have memory leaks. Moulinette will test that.
*/

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

static void    ft_putstr(char *s, int *len)
{
    if (!s)
        s = "(null)";
    while (*s)
        *len += write(1, s++, 1);
}

static void    ft_putnbr(long n, int base, int *len)
{
    char *hex = "0123456789abcdef";

    if (n < 0)
    {
        *len += write(1, "-", 1);
        n = -n;
    }
    if (n >= base)
        ft_putnbr(n / base, base, len);
    *len += write(1, &hex[n % base], 1);
}

int ft_printf(const char *format, ...)
{
    va_list args;
    int     len = 0;

    va_start(args, format);
    while (*format)
    {
        if (*format == '%' && *(format + 1))
        {
            format++;
            if (*format == 's')
                ft_putstr(va_arg(args, char *), &len);
            else if (*format == 'd')
                ft_putnbr(va_arg(args, int), 10, &len);
            else if (*format == 'x')
                ft_putnbr(va_arg(args, unsigned int), 16, &len);
        }
        else
            len += write(1, format, 1);
        format++;
    }
    va_end(args);
    return (len);
}
