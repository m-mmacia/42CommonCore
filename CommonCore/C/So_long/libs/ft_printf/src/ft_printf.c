#include "../lib/ft_printf.h"

int	ft_type(va_list args, char c)
{
	int		len;
	char	str;

	len = 0;
	if (c == 'c')
	{
		str = va_arg(args, int);
		return (write(1, &str, 1));
	}
	else if (c == 's')
		return (ft_str(va_arg(args, char *)));
	else if (c == 'p')
		ft_ptr(va_arg(args, unsigned long long), &len);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(args, int), &len);
	else if (c == 'u')
		ft_putnbr_u(va_arg(args, unsigned int), &len);
	else if (c == 'x')
		ft_ptr_x(va_arg(args, unsigned int), &len, 'x');
	else if (c == 'X')
		ft_ptr_x(va_arg(args, unsigned int), &len, 'X');
	else if (c == '%')
		return (write(1, "%", 1));
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			i;
	int			len;

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += ft_type(args, format[i + 1]);
			i++;
		}
		else
		{
			len += write(1, &format[i], 1);
		}
		i++;
	}
	return (len);
}

/*int main(void)
{
	printf("%d", ft_printf("%x et %x\n", 1234, 1234));
	printf("%d", printf("%x et %x\n", 1234, 1234));
}*/
