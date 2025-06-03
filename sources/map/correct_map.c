/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machouba <machouba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:08:01 by machouba          #+#    #+#             */
/*   Updated: 2024/05/13 10:51:24 by machouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

bool	valid_character(t_game *game, int y, int x)
{
	if (!(ft_strchr("01CEP", game->plot.map[y][x])))
		return (false);
	return (true);
}

bool	maps_walls(t_game *game, int y, int x)
{
	if ((game->plot.map[game->plot.height - 1][x] != '1')
			|| (game->plot.map[0][x] != '1') || (game->plot.map[y][0] != '1')
				|| (game->plot.map[y][game->plot.lenght - 1] != '1'))
		return (false);
	return (true);
}

bool	rectangular(t_game *game)
{
	if (game->plot.lenght == game->plot.height)
		return (false);
	return (true);
}

void	is_items_valid(t_game *game, t_skin *items, char *str, int fd)
{
	if (!(items->collect > 0 && items->exit == 1 && items->start == 1))
	{
		free(str);
		close(fd);
		end_game("Invalide items", game, file_error);
	}
}

bool	double_line(char *str, int i)
{
	return ((str[i] == '\n') && (ft_strchr("\n\0", str[i + 1])));
}
