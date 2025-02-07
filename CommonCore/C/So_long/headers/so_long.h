#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libs/minilibx/mlx.h"
# include "../libs/ft_printf/lib/ft_printf.h"
# include "../libs/gnl/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>

typedef struct s_mapcheck
{
	int	c_found;
	int	e_found;
	int	p_found;
}		t_mapcheck;

typedef struct s_data
{
	t_mapcheck	mapcheck;
	void		*mlx_ptr;
	void		*win_ptr;
	int			zqsd_moove;
	int			player_x;
	int			player_y;
	int			collected_items;
	char		**map;
	int			map_width;
	int			map_height;
	void		*floor_img;
	void		*wall_img;
	void		*player_img;
	void		*item_img;
	void		*exit_img;
	int			exit_found;
	int			c_count;
}			t_data;

int		read_map(char *file_path, t_data *data);
void	draw_game(t_data *data, int x, int y, char cell);
int		on_keypress(int keysym, t_data *data);
int		is_path_valid(t_data *data);
void	get_map_dimensions(char *file_path, int *width, int *height);
void	free_exit(t_data *data);

#endif
