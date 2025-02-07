#include "headers/so_long.h"

void	dfs(t_data *data, int y, int x, int *visited)
{
	if (x < 0 || x >= data->map_width || y < 0 || y >= data->map_height
		|| visited[y * data->map_width + x] || data->map[y][x] == '1')
		return ;
	visited[y * data->map_width + x] = 1;
	if (data->map[y][x] == 'C')
		(data->c_count)++;
	if (data->map[y][x] == 'E' && data->c_count == data->mapcheck.c_found)
		data->exit_found = 1;
	dfs(data, y + 1, x, visited);
	dfs(data, y - 1, x, visited);
	dfs(data, y, x + 1, visited);
	dfs(data, y, x - 1, visited);
}

int	is_path_valid(t_data *data)
{
	int	*visited;

	data->c_count = 0;
	data->exit_found = 0;
	visited = calloc(data->map_height * data->map_width, sizeof(int));
	if (!visited)
	{
		free(visited);
		return (ft_printf("Error: Memory allocation failed\n"), 0);
	}
	dfs(data, data->player_y, data->player_x, visited);
	free(visited);
	if (!(data->c_count == data->mapcheck.c_found && data->exit_found))
		return (0);
	return (1);
}
