#include "unistd.h"
#include "stdarg.h"
#include "stdio.h"

int	ft_putstr(char *str)
{
	int	i = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[i])
		i += write(1, &str[i], 1);
	return (i);
}

int	ft_putnbr(long nbr, int base)
{
 	char	*hex = "0123456789abcdef";
	int	i = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		i += write(1, "-", 1);
	}
	if (nbr >= base)
		i += ft_putnbr(nbr/base, base);
	i += write(1, &hex[nbr%base], 1);
	return (i);
}

int	ft_printf(const char *format, ...)
{
	int	i = 0;
	int	len = 0;
	va_list	ptr;
	va_start (ptr, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 's')
				len += ft_putstr(va_arg(ptr, char *));
			if (format[i] == 'd')
				len += ft_putnbr(va_arg(ptr, int), 10);
			if (format[i] == 'x')
				len += ft_putnbr(va_arg(ptr, unsigned int), 16);
		}
		else
			len += write(1, &format[i], 1);
		i++;
	}
	va_end(ptr);
	return (len);
}

int	main(void)
{
	printf("%s\n", "toto");
	printf("%d\n", 42);
	printf("%x\n", 42);
}
