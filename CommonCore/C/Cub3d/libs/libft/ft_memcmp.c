#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*chr1;
	const unsigned char	*chr2;

	chr1 = s1;
	chr2 = s2;
	while (n--)
	{
		if (*chr1 != *chr2)
			return (*chr1 - *chr2);
		chr1++;
		chr2++;
	}
	return (0);
}
