#include "headers/so_long.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	get_map_dimensions(char *file_path, int *width, int *height)
{
	int		fd;
	char	*line;
	int		line_length;

	*width = 0;
	*height = 0;
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		exit(ft_printf("Error : file open"));
	line = get_next_line(fd);
	while (line != NULL)
	{
		line_length = ft_strlen(line) - 1;
		if (line_length > *width)
			*width = line_length;
		(*height)++;
		free(line);
		line = get_next_line(fd);
	}
	if (*height < 3 || *width < 3)
		exit(ft_printf("Error : map empty"));
	close(fd);
}
