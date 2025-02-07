#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		i;
	int		i2;

	i = 0;
	i2 = 0;
	dest = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!s1 || !s2 || !dest)
	{
		return (NULL);
	}
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[i2])
	{
		dest[i] = s2[i2];
		i++;
		i2++;
	}
	dest[i] = '\0';
	return (dest);
}
