#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*dest;

	dest = malloc(size * count);
	if (dest != NULL)
		ft_bzero(dest, size * count);
	return (dest);
}
