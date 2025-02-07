#include "../lib/ft_printf.h"

int	ft_str(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[++i])
		write(1, &str[i], 1);
	return (i);
}

void	ft_putchar(char c)
{
	write (1, &c, 1);
}
