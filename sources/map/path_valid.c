/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_valid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machouba <machouba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:05:48 by machouba          #+#    #+#             */
/*   Updated: 2024/05/10 14:46:28 by machouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	valid_path_player(char **cpy_map, int i, int j, t_point coord)
{
	int	path_ok;

	path_ok = 0;
	if (cpy_map[i][j] == 'E')
		return (1);
	cpy_map[i][j] = 'V';
	if (is_valid_pos(i, j + 1, coord.y, coord.x) && (cpy_map[i][j
			+ 1] == '0' || cpy_map[i][j + 1] == 'C' || cpy_map[i][j
				+ 1] == 'E'))
		path_ok += valid_path_player(cpy_map, i, j + 1, coord);
	if (is_valid_pos(i, j - 1, coord.y, coord.x) && (cpy_map[i][j
			- 1] == '0' || cpy_map[i][j - 1] == 'C' || cpy_map[i][j
				- 1] == 'E'))
		path_ok += valid_path_player(cpy_map, i, j - 1, coord);
	if (is_valid_pos(i + 1, j, coord.y, coord.x) && (cpy_map[i + 1]
			[j] == '0' || cpy_map[i + 1][j] == 'C' || cpy_map[i + 1][j] == 'E'))
		path_ok += valid_path_player(cpy_map, i + 1, j, coord);
	if (is_valid_pos(i - 1, j, coord.y, coord.x) && (cpy_map[i - 1]
			[j] == '0' || cpy_map[i - 1][j] == 'C' || cpy_map[i - 1][j] == 'E'))
		path_ok += valid_path_player(cpy_map, i - 1, j, coord);
	return (path_ok);
}

static int	valid_path_collect(char **cpy_map, int i, int j, t_point coord)
{
	int	path_ok;

	path_ok = 0;
	if (cpy_map[i][j] == 'P')
		return (1);
	cpy_map[i][j] = 'V';
	if (is_valid_pos(i, j + 1, coord.y, coord.x) && (cpy_map[i][j
			+ 1] == '0' || cpy_map[i][j + 1] == 'C' || cpy_map[i][j
				+ 1] == 'P'))
		path_ok += valid_path_collect(cpy_map, i, j + 1, coord);
	if (is_valid_pos(i, j - 1, coord.y, coord.x) && (cpy_map[i][j
			- 1] == '0' || cpy_map[i][j - 1] == 'C' || cpy_map[i][j
				- 1] == 'P'))
		path_ok += valid_path_collect(cpy_map, i, j - 1, coord);
	if (is_valid_pos(i + 1, j, coord.y, coord.x) && (cpy_map[i + 1]
			[j] == '0' || cpy_map[i + 1][j] == 'C' || cpy_map[i + 1][j] == 'P'))
		path_ok += valid_path_collect(cpy_map, i + 1, j, coord);
	if (is_valid_pos(i - 1, j, coord.y, coord.x) && (cpy_map[i - 1]
			[j] == '0' || cpy_map[i - 1][j] == 'C' || cpy_map[i - 1][j] == 'P'))
		path_ok += valid_path_collect(cpy_map, i - 1, j, coord);
	return (path_ok);
}

void	free_map_test(char **map, int x)
{
	int	i;

	i = 0;
	while (i < x)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	check_path_player(t_game *game, t_point coord)
{
	int		j;
	char	**cpy_map;

	int (i) = 0;
	j = 0;
	while (i < coord.y)
	{
		j = 0;
		while (j < coord.x)
		{
			if (game->plot.map[i][j] == 'P')
			{
				cpy_map = copy_map(game, coord.y, coord.x);
				if (valid_path_player(cpy_map, i, j, coord) == 0)
				{
					free_map_test(cpy_map, coord.y);
					end_game("Invalid path palyer -> collect -> exit",
						game, map_char_error);
				}
				free_map_test(cpy_map, coord.y);
			}
			j++;
		}
		i++;
	}
}

void	check_path_collect(t_game *game, t_point coord)
{
	int		j;
	char	**cpy_map;

	int (i) = 0;
	j = 0;
	while (i < coord.y)
	{
		j = 0;
		while (j < coord.x)
		{
			if (game->plot.map[i][j] == 'C')
			{
				cpy_map = copy_map(game, coord.y, coord.x);
				if (valid_path_collect(cpy_map, i, j, coord) == 0)
				{
					free_map_test(cpy_map, coord.y);
					end_game("Invalid path palyer -> collect -> exit",
						game, map_char_error);
				}
				free_map_test(cpy_map, coord.y);
			}
			j++;
		}
		i++;
	}
}
