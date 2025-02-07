#include "headers/so_long.h"

int	is_map_closed(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < data->map_width)
	{
		if (data->map[0][x] != '1' || data->map[data->map_height - 1][x] != '1')
			return (0);
		x++;
	}
	x = 0;
	while (y < data->map_height)
	{
		if (data->map[y][0] != '1' || data->map[y][data->map_width - 1] != '1')
			return (0);
		y++;
	}
	return (1);
}

void	init_xpm(t_data *data)
{
	int	w;
	int	h;

	w = 64;
	h = 64;
	data->floor_img = mlx_xpm_file_to_image(data->mlx_ptr, "t/f.xpm", &w, &h);
	data->wall_img = mlx_xpm_file_to_image(data->mlx_ptr, "t/w.xpm", &w, &h);
	data->player_img = mlx_xpm_file_to_image(data->mlx_ptr, "t/p.xpm", &w, &h);
	data->item_img = mlx_xpm_file_to_image(data->mlx_ptr, "t/i.xpm", &w, &h);
	data->exit_img = mlx_xpm_file_to_image(data->mlx_ptr, "t/e.xpm", &w, &h);
	if (!data->floor_img || !data->wall_img
		|| !data->player_img || !data->item_img || !data->exit_img)
		return ;
}

void	read_map_objects(t_data *data, char *line, int y, int fd)
{
	int	x;

	while (line != NULL)
	{
		data->map[y] = line;
		x = 0;
		while (line[x] != '\0')
		{
			if (line[x] == 'P' && data->player_x == -1
				&& data->player_y == -1)
			{
				data->player_x = x;
				data->player_y = y;
			}
			if (line[x] == 'C')
				data->mapcheck.c_found++;
			if (line[x] == 'P')
				data->mapcheck.p_found++;
			if (line[x] == 'E')
				data->mapcheck.e_found++;
			x++;
		}
		line = get_next_line(fd);
		y++;
	}
}

int	read_map(char *file_path, t_data *data)
{
	int		fd;
	char	*line;
	int		y;

	init_xpm(data);
	data->player_x = -1;
	data->player_y = -1;
	y = 0;
	data->map = malloc(sizeof(char *) * data->map_height);
	if (!data->map)
		return (ft_printf("Error : allocate memory for map\n"), 0);
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (ft_printf("Error : opening file\n"), 0);
	line = get_next_line(fd);
	read_map_objects(data, line, y, fd);
	close(fd);
	if (!is_map_closed(data))
		return (ft_printf("Error : The map is not close off by wall\n"), 0);
	if (data->player_x == -1 || data->player_y == -1)
		return (ft_printf("Error : P not found\n"), 0);
	if (data->mapcheck.e_found != 1
		|| data->mapcheck.c_found < 1 || data->mapcheck.p_found != 1)
		return (ft_printf("Error : E, C, or P.\n"), 0);
	return (1);
}
