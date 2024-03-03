#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

// Output single characters
int	ft_putchar(char c)
{
	if (write(1, &c, 1) == 0)
		return (0);
	else
		return (1);
}

// Output characters in the string and take note of how many letters there are
int	ft_putstr(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!str)
		str = "(null)";
	while (str[i])
	{
		ft_putchar(str[i++]);
		count++;
	}
	return (count);
}

// Output the number of integers to the standard input while taking note of the count
int	ft_putnbr(int nbr)
{
	char	digit;
	int	count;

	count = 0;
	if (nbr == -2147483648)
	{
		count += ft_putstr("-2147483648");
		return (count);
	}
	else if (nbr < 0)
	{
		count += ft_putchar('-');
		nbr = -nbr;
	}
    if (nbr >= 10)
		count += ft_putnbr(nbr / 10);
	digit = (nbr % 10) + '0';
	count += write(1, &digit, 1);
    return (count);
}

// Outputs the hexadecimal equivalent to the integer while taking note of how many characters was printed
int ft_print_hex(unsigned int nbr, int *count)
{
    char    str[16] = "0123456789abcdef";

    if (nbr >= 16)
	ft_print_hex(nbr / 16, count);
    *count += write(1, &str[nbr % 16], 1);
    return (*count); // return int value by dereferencing pointer instead of returning memory address
}

// Simplified version of printf and use variable arguments
int	ft_printf(const char *format, ...)
{
	va_list			args;
	char			*s;
	int				d;
	int				count;
	unsigned int	x;

	count = 0;
    va_start(args, format);
    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == 's')
            {
                s = va_arg(args, char *);
                count += ft_putstr(s);
            }
            else if (*format == 'd')
            {
                d = va_arg(args, int);
                count += ft_putnbr(d);
            }
            else if (*format == 'x')
            {
                x = va_arg(args, unsigned int);
                ft_print_hex(x, &count);
            }
        }
        else
		count += write(1, "%", 1);
        format++;
    }
    va_end(args);
	return (count);
}
/*
int main(void)
{
    ft_printf("%s\n", "toto");
    ft_printf("Magic is %s is %d\n", "number", 42);
    ft_printf("Hexadecimal for %d is %x\n", 42, 42);
    return (0);
}
*/
