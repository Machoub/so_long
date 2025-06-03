/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machouba <machouba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 18:35:00 by khaoulasard       #+#    #+#             */
/*   Updated: 2024/05/08 15:14:20 by machouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	checker_map(t_game *game, int y, int x)
{
	if (!maps_walls(game, y, x))
		end_game("Map invalid (walls)", game, design_map_error);
	else if (!valid_character(game, y, x))
		end_game("Map invalid (character)", game, design_map_error);
	return ;
}

void	parsing_map(t_game *game)
{
	t_point	coord;

	coord.y = 0;
	while (game->plot.map[coord.y])
	{
		coord.x = 0;
		while (game->plot.map[coord.y][coord.x])
		{
			checker_map(game, coord.y, coord.x);
			coord.x++;
		}
		coord.y++;
	}
	check_path_collect(game, coord);
	check_path_player(game, coord);
	return ;
}
