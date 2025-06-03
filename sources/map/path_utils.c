/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machouba <machouba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:02:44 by machouba          #+#    #+#             */
/*   Updated: 2024/05/07 09:56:22 by machouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	is_valid_pos(int i, int j, int y, int x)
{
	return (i > 0 && i < y && j > 0 && j < x);
}

char	**alloc_map_mem(t_game *game, int y, int x)
{
	char	**new_map;
	int		j;

	int (i) = 0;
	new_map = (char **)malloc(sizeof(char *) * (game->plot.height + 1));
	if (!new_map)
		return (NULL);
	while (i < y)
	{
		new_map[i] = (char *)malloc(sizeof(char *) * (game->plot.lenght + 1));
		if (new_map[i] == NULL)
		{
			j = 0;
			while (j < i)
			{
				free(new_map[j]);
				j++;
			}
			free_map_test(new_map, x);
			return (NULL);
		}
		i++;
	}
	new_map[y] = NULL;
	return (new_map);
}

char	**copy_map(t_game *game, int y, int x)
{
	char	**ptr_map;
	int		i;
	int		j;

	ptr_map = alloc_map_mem(game, y, x);
	if (!ptr_map)
		return (NULL);
	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			ptr_map[i][j] = game->plot.map[i][j];
			j++;
		}
		ptr_map[i][x] = '\0';
		i++;
	}
	return (ptr_map);
}
