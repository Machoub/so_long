/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machouba <machouba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:51:26 by machouba          #+#    #+#             */
/*   Updated: 2024/05/13 10:42:22 by machouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	end_game2(char *msg, t_game *game)
{
	ft_printf("Error\n%s\n", msg);
	kill_image(game);
	return ;
}

static void	line_valid(char **map, t_game *game, int fd)
{
	t_point	point;
	int		i;

	i = 0;
	point.x = 0;
	point.y = ft_strlen(map[0]);
	while (map[i])
	{
		point.x = ft_strlen(map[i]);
		if (point.x != point.y)
		{
			free_map(game);
			close(fd);
			end_game("Error : line not valid", game, error);
		}
		i++;
	}
}

int	len_map(char **map, t_game *game, int fd)
{
	line_valid(map, game, fd);
	return (ft_strlen(map[0]));
}

t_skin	init_counter(void)
{
	t_skin	counter;

	counter.empty = 0;
	counter.collect = 0;
	counter.exit = 0;
	counter.movements = 0;
	counter.start = 0;
	return (counter);
}
