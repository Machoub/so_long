/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machouba <machouba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:01:03 by machouba          #+#    #+#             */
/*   Updated: 2024/05/09 14:49:21 by machouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_image_nul(t_game *game)
{
	game->wall.ptr = NULL;
	game->floor.ptr = NULL;
	game->item.ptr = NULL;
	game->dj_close.ptr = NULL;
	game->dj_open.ptr = NULL;
	game->player.ptr = NULL;
	game->player_left.ptr = NULL;
	game->player_right.ptr = NULL;
	game->player_upper.ptr = NULL;
}

void	print_map_string(t_game *game)
{
	char	*string;

	string = ft_itoa(game->i.movements);
	mlx_string_put(game->mlx_ptr, game->windows_ptr, 40,
		20, 0xFFFFFF, "Move: ");
	mlx_string_put(game->mlx_ptr, game->windows_ptr, 75,
		20, 0xFFFFFF, string);
	free(string);
	return ;
}

int	red_cross(t_game *game)
{
	end_game("", game, event_end);
	return (0);
}

t_point	get_screen_size(t_game *game)
{
	t_point	point;

	mlx_get_screen_size(game->mlx_ptr, &point.x, &point.y);
	return (point);
}

bool	not_window(t_game *game)
{
	t_point	screen_size;

	screen_size = get_screen_size(game);
	return (((game->plot.lenght * SPR_SZ) > screen_size.x)
		|| ((game->plot.height * SPR_SZ) > screen_size.y));
}
