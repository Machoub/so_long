/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machouba <machouba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:16:01 by machouba          #+#    #+#             */
/*   Updated: 2024/05/09 13:41:15 by machouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	is_right(t_game *game)
{
	if (!(game->plot.map[(game->player.y / SPR_SZ)][((game->player.x
					+ SPR_SZ) / SPR_SZ)] != '1'))
		return (0);
	else if (!(game->plot.map[(game->player.y / SPR_SZ)][((game->player.x
					+ SPR_SZ) / SPR_SZ)] != 'E'))
	{
		if (game->i.collect == 0)
			return (1);
		return (0);
	}
	return (1);
}

static void	check_if_right(t_game *game)
{
	if (game->player.x < ((game->plot.lenght * SPR_SZ) - (SPR_SZ * 2)))
	{
		if (is_right(game) != 0)
		{
			game->player.x += SPR_SZ;
			render_map(game);
			print_moves(game);
		}
	}
	return ;
}

void	move_right(t_game *game)
{
	check_if_right(game);
	game->player.mem = right;
	mlx_put_image_to_window(game->mlx_ptr, game->windows_ptr,
		game->player_right.ptr, game->player.x, game->player.y);
	return ;
}
