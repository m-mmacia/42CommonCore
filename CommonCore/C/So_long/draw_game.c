#include "headers/so_long.h"

void	draw_game(t_data *data, int x, int y, char cell)
{
	void	*img_to_draw;

	while (++y < data->map_height)
	{
		x = -1;
		while (++x < data->map_width)
		{	
			if (cell == '0')
				img_to_draw = data->floor_img;
			if (cell == '1')
				img_to_draw = data->wall_img;
			if (cell == 'C')
				img_to_draw = data->item_img;
			if (cell == 'E')
				img_to_draw = data->exit_img;
			if (cell == 'P')
				img_to_draw = data->player_img;
			if (img_to_draw != NULL)
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					img_to_draw, x * 64, y * 64);
			cell = data->map[y][x];
		}
	}
}
