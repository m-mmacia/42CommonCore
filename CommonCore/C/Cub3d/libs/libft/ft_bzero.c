#include "libft.h"

void	ft_bzero(void *ptr, size_t count)
{
	char	*ptrchar;

	ptrchar = ptr;
	while (count > 0)
	{
		*ptrchar = '\0';
		ptrchar++;
		count--;
	}
}
