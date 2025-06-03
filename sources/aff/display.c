/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machouba <machouba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:01:09 by machouba          #+#    #+#             */
/*   Updated: 2024/05/13 10:44:43 by machouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_image	new_sprite(t_game *game, char *img_xpm)
{
	t_image	img;

	img.ptr = mlx_xpm_file_to_image(game->mlx_ptr, img_xpm, &img.x, &img.y);
	if (img.ptr == NULL)
		end_game("image failed", game, image_error);
	return (img);
}

void	init_window(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		return ;
	if (not_window(game))
	{
		free_map(game);
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
		end_game("Err map size larger than resolution", game, error);
	}
	else
	{
		game->windows_ptr = mlx_new_window(game->mlx_ptr,
				(game->plot.lenght * SPR_SZ), (game->plot.height
					* SPR_SZ), WINDOW_NAME);
	}
}

void	init_image(t_game *game)
{
	init_image_nul(game);
	game->wall = new_sprite(game, WALL);
	game->floor = new_sprite(game, FLOOR);
	game->item = new_sprite(game, ITEM);
	game->dj_close = new_sprite(game, DJ_CLOSE);
	game->dj_open = new_sprite(game, DJ_OPEN);
	game->player = new_sprite(game, PLAYER);
	game->player_left = new_sprite(game, PLAYER_LEFT);
	game->player_right = new_sprite(game, PLAYER_RIGHT);
	game->player_upper = new_sprite(game, PLAYER_UP);
	return ;
}

int	check_env2(char **envp)
{
	const char	*env;
	char		*val_va;
	int			i;

	env = "DISPLAY";
	val_va = NULL;
	i = 0;
	while (envp[i])
	{
		if (ft_strstr(envp[i], (char *)env) == envp[i])
		{
			val_va = ft_strchr(envp[i], '=') + 1;
			break ;
		}
		i++;
	}
	if (val_va == NULL)
		return (0);
	else
		return (1);
}
