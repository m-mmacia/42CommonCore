#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

void	ft_putnbr(int nb, int *i);
int		ft_printf(const char *format, ...);
int		ft_str(char *str);
void	ft_ptr(unsigned long long ptr, int *len);
void	ft_putnbr_u(unsigned int nb, int *len);
void	ft_ptr_x(unsigned int ptr, int *len, char x_or_x);
void	ft_putchar(char c);

#endif
