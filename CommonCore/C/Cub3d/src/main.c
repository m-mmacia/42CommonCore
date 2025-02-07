#include "../header/cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (printf("Error : ./cub3d (map.cub)\n"));
	ft_init(&data, argv[1], -1, -1);
	ft_load_textures(&data);
	mlx_loop_hook(data.mlx_ptr, ft_render, &data);
	mlx_hook(data.win_ptr, 2, 1L << 0, ft_key_press, &data);
	mlx_hook(data.win_ptr, 17, 1L << 17, ft_wrapper_free, &data);
	mlx_loop(data.mlx_ptr);
}
