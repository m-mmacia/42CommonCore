#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	i2;

	i = 0;
	i2 = ft_strlen(dest);
	if (size <= i2)
	{
		return (size + ft_strlen(src));
	}
	while (src[i] != '\0' && i2 + 1 < size)
	{
		dest[i2] = src[i];
		i++;
		i2++;
	}
	dest[i2] = '\0';
	return (ft_strlen(dest) + ft_strlen(&src[i]));
}
