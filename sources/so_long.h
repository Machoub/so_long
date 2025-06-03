/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machouba <machouba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:51:21 by machouba          #+#    #+#             */
/*   Updated: 2024/05/13 10:51:49 by machouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"
# include "../libft/inc/get_next_line.h"
# include <stdarg.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

# define SPR_SZ 64
# define WINDOW_NAME "./so_long"

# define ESC 65307
# define UP 119
# define DOWN 115
# define RIGHT 100
# define LEFT 97

# define KEY_PRESS 02
# define DESTROY_NOTIF 17
# define EXPOSE 12

# define KEY_PRESS_MASK 1
# define EXPOSURE_MASK 32768
# define NO_EVENT_MASK 0

# define WALL "./img_xpm/wall.xpm"
# define FLOOR "./img_xpm/floor.xpm"
# define ITEM "./img_xpm/item.xpm"
# define DJ_OPEN "./img_xpm/dj_open.xpm"
# define DJ_CLOSE "./img_xpm/dj_close.xpm"
# define PLAYER "./img_xpm/player.xpm"
# define PLAYER_LEFT "./img_xpm/player_left.xpm"
# define PLAYER_RIGHT "./img_xpm/player_right.xpm"
# define PLAYER_UP "./img_xpm/player_up.xpm"

typedef struct s_point
{
	int	x;
	int	y;
}			t_point;

typedef struct s_image
{
	void	*ptr;
	int		*pxl;
	int		line_size;
	int		mem;
	int		x;
	int		y;
	int		mouv;
}			t_image;

typedef struct s_skin
{
	int	empty;
	int	collect;
	int	exit;
	int	start;
	int	movements;
}		t_skin;

typedef struct s_draw
{
	char	*line;
	char	**map;
	int		height;
	int		lenght;
}			t_draw;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*windows_ptr;
	t_skin		i;
	t_draw		plot;
	t_image		player;
	t_image		player_left;
	t_image		player_right;
	t_image		player_upper;
	t_image		floor;
	t_image		wall;
	t_image		item;
	t_image		dj_open;
	t_image		dj_close;
}				t_game;

enum	e_state
{
	event_end = -1,
	game_over = -1,
	error = 2,
	file_error = 3,
	map_char_error = 4,
	design_map_error = 5,
	image_error = 6,
	env_error = 7,
};

enum	e_dir
{
	up,
	down,
	left,
	right,
};

void	end_game(char *message, t_game *game, enum e_state i);
int		check_env(char **envp);
void	kill_image(t_game *game);
void	free_map(t_game *game);
void	init_map(t_game *game, char *path);
bool	double_line(char *str, int i);
void	is_items_valid(t_game *game, t_skin *items, char *str, int fd);
bool	rectangular(t_game *game);
bool	maps_walls(t_game *game, int y, int x);
bool	valid_character(t_game *game, int y, int x);
int		len_map(char **map, t_game *game, int fd);
t_skin	init_counter(void);
void	end_game2(char *msg, t_game *game);
void	parsing_map(t_game *game);
char	**copy_map(t_game *game, int y, int x);
char	**alloc_map_mem(t_game *game, int y, int x);
int		is_valid_pos(int i, int j, int y, int x);
void	free_map_test(char **map, int x);
void	check_path_collect(t_game *game, t_point coord);
void	check_path_player(t_game *game, t_point coord);
void	init_window(t_game *game);
t_image	new_sprite(t_game *game, char *img_xpm);
void	init_image(t_game *game);
bool	not_window(t_game *game);
t_point	get_screen_size(t_game *game);
int		red_cross(t_game *game);
void	init_image_nul(t_game *game);
void	render_map(t_game *game);
void	player_init(t_game *game);
int		mini_maker(t_game *game);
int		key_check(int keycode, t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
void	move_up(t_game *game);
void	print_moves(t_game *game);
void	kill_image2(t_game *game);
void	print_map_string(t_game *game);
int		check_env2(char **envp);

#endif