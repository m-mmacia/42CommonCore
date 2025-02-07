#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*duplic;
	int		i;

	i = -1;
	duplic = malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!duplic)
		return (NULL);
	while (str[++i])
		duplic[i] = str[i];
	duplic[i] = '\0';
	return (duplic);
}
