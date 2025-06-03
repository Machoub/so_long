/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machouba <machouba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:07:42 by machouba          #+#    #+#             */
/*   Updated: 2024/05/09 14:14:27 by machouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	key_check(int keycode, t_game *game)
{
	game->player.mem = 0;
	if (keycode == ESC)
		end_game("", game, event_end);
	else if (keycode == UP)
		move_up(game);
	else if (keycode == DOWN)
		move_down(game);
	else if (keycode == RIGHT)
		move_right(game);
	else if (keycode == LEFT)
		move_left(game);
	return (0);
}

void	print_moves(t_game *game)
{
	game->i.movements += 1;
	if (game->plot.map[game->player.y / SPR_SZ][game->player.x / SPR_SZ]
			== 'C')
	{
		game->plot.map[game->player.y / SPR_SZ][game->player.x / SPR_SZ] = '0';
		game->i.collect--;
	}
	else if (game->plot.map[game->player.y / SPR_SZ][game->player.x / SPR_SZ]
			== 'E' && game->i.collect == 0)
	{
		end_game("\nend", game, game_over);
	}
	print_map_string(game);
	ft_putstr_fd("\rMove: ", 1);
	ft_putnbr_fd(game->i.movements, 1);
	return ;
}
