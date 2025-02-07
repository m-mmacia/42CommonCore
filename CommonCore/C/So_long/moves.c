#include "headers/so_long.h"

void	msg_move(t_data *data, int next_x, int next_y)
{
	data->map[data->player_y][data->player_x] = '0';
	data->player_x = data->player_x + next_x;
	data->player_y = data->player_y + next_y;
	data->map[data->player_y][data->player_x] = 'P';
	ft_printf("Numbers of moves : %d\n", ++data->zqsd_moove);
	draw_game(data, -1, -1, data->map[0][0]);
}

void	free_exit(t_data *data)
{
	int	i;

	i = 0;
	mlx_destroy_image(data->mlx_ptr, data->floor_img);
	mlx_destroy_image(data->mlx_ptr, data->wall_img);
	mlx_destroy_image(data->mlx_ptr, data->player_img);
	mlx_destroy_image(data->mlx_ptr, data->item_img);
	mlx_destroy_image(data->mlx_ptr, data->exit_img);
	while (i < data->map_height)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
}

void	process_movement(int next_x, int next_y, t_data *data)
{
	char	next_cell;

	next_cell = data->map[data->player_y + next_y][data->player_x + next_x];
	if (next_cell != '1')
	{
		if (next_cell == 'C')
		{
			data->collected_items++;
			ft_printf("Item collected !\n");
		}
		else if (next_cell == 'E'
			&& data->mapcheck.c_found == data->collected_items)
		{
			ft_printf("All items collected! Exiting...\n");
			sleep(1);
			free_exit(data);
		}
		else if (next_cell == 'E')
		{
			ft_printf("Cannot exit yet. Items remaining: %d\n",
				data->mapcheck.c_found - data->collected_items);
			return ;
		}
		msg_move(data, next_x, next_y);
	}
}

int	on_keypress(int keysym, t_data *data)
{
	int	next_x;
	int	next_y;

	next_x = 0;
	next_y = 0;
	if (keysym == XK_Escape)
		free_exit(data);
	if (keysym == XK_Left || keysym == XK_Right
		|| keysym == XK_Up || keysym == XK_Down)
		return (0);
	if (keysym == XK_z || keysym == XK_w)
		next_y--;
	else if (keysym == XK_q || keysym == XK_a)
		next_x--;
	else if (keysym == XK_s)
		next_y++;
	else if (keysym == XK_d)
		next_x++;
	process_movement(next_x, next_y, data);
	return (0);
}
