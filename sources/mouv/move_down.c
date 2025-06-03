/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_down.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machouba <machouba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:33:03 by machouba          #+#    #+#             */
/*   Updated: 2024/05/06 17:52:34 by machouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	is_down(t_game *game)
{
	if (!((game->plot.map[((game->player.y + SPR_SZ)
						/ SPR_SZ)][game->player.x / SPR_SZ]) != '1'))
		return (0);
	else if (!((game->plot.map[((game->player.y + SPR_SZ)
						/ SPR_SZ)][game->player.x / SPR_SZ]) != 'E'))
	{
		if (game->i.collect == 0)
			return (1);
		return (0);
	}
	return (1);
}

static void	check_if_down(t_game *game)
{
	if (game->player.y < ((game->plot.height * SPR_SZ) - (SPR_SZ * 2)))
	{
		if (is_down(game) != 0)
		{
			game->player.y += SPR_SZ;
			render_map(game);
			print_moves(game);
		}
	}
	return ;
}

void	move_down(t_game *game)
{
	check_if_down(game);
	game->player.mem = down;
	mlx_put_image_to_window(game->mlx_ptr, game->windows_ptr,
		game->player.ptr, game->player.x, game->player.y);
	return ;
}
