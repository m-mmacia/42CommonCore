#include "../lib/ft_printf.h"

void	ft_putnbr(int nb, int *len)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*len) += 11;
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		(*len) += 1;
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10, len);
		ft_putnbr(nb % 10, len);
	}
	else
	{
		ft_putchar(nb + '0');
		(*len) += 1;
	}
}

void	ft_putnbr_u(unsigned int nb, int *len)
{
	if (nb >= 10)
	{
		ft_putnbr(nb / 10, len);
		ft_putnbr(nb % 10, len);
	}
	else
	{
		ft_putchar(nb + '0');
		(*len) += 1;
	}
}

void	ft_ptr(unsigned long long ptr, int *len)
{
	char	str[25];
	int		i;
	char	*base;

	base = "0123456789abcdef";
	i = 0;
	if (ptr == 0)
		(*len) += write(1, "(nil)", 5);
	else
		(*len) += write(1, "0x", 2);
	while (ptr != 0)
	{
		str[i] = base[ptr % 16];
		ptr = ptr / 16;
		i++;
	}
	while (i--)
		(*len) += write(1, &str[i], 1);
}

void	ft_ptr_x(unsigned int ptr, int *len, char x_or_x)
{
	int		i;
	char	str[25];
	char	*base;

	i = 0;
	if (ptr == 0)
		(*len) += write(1, "0", 1);
	if (x_or_x == 'x')
		base = "0123456789abcdef";
	else if (x_or_x == 'X')
		base = "0123456789ABCDEF";
	while (ptr != 0)
	{
		str[i] = base[ptr % 16];
		ptr = ptr / 16;
		i++;
	}
	while (i--)
		(*len) += write(1, &str[i], 1);
}
