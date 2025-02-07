#include "headers/so_long.h"

int	close_window(t_data *data)
{
	free_exit(data);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	data.mapcheck.c_found = 0;
	data.mapcheck.e_found = 0;
	data.mapcheck.p_found = 0;
	data.zqsd_moove = 0;
	data.collected_items = 0;
	data.mlx_ptr = mlx_init();
	if (argc != 2)
		return (ft_printf("Usage : ./so_long map.ber\n"), 0);
	if (!data.mlx_ptr)
		return (ft_printf("Error initializing mlx\n"), 0);
	get_map_dimensions(argv[1], &data.map_width, &data.map_height);
	data.win_ptr = mlx_new_window(data.mlx_ptr,
			data.map_width * 64, data.map_height * 64, "so_long");
	if (!data.win_ptr)
		return (ft_printf("Error creating window\n"), 0);
	if (!read_map(argv[1], &data))
		return (ft_printf("Error : read map\n"), 0);
	draw_game(&data, -1, -1, data.map[0][0]);
	if (!is_path_valid(&data))
		return (ft_printf("Error : path invalid for E, C, or P\n"), 0);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, on_keypress, &data);
	mlx_hook(data.win_ptr, 17, 0, close_window, &data);
	mlx_loop(data.mlx_ptr);
}
