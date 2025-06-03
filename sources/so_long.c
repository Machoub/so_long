/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machouba <machouba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:51:16 by machouba          #+#    #+#             */
/*   Updated: 2024/05/10 15:26:26 by machouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_char(const char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

static void	init_hook(t_game *game, int event, int mask, int (*f)())
{
	mlx_hook(game->windows_ptr, event, mask, f, game);
}

static void	init_game(t_game *game, char *map)
{
	init_map(game, map);
	parsing_map(game);
	init_window(game);
	init_image(game);
	render_map(game);
	init_hook(game, KEY_PRESS, KEY_PRESS_MASK, key_check);
	init_hook(game, DESTROY_NOTIF, NO_EVENT_MASK, red_cross);
	init_hook(game, EXPOSE, EXPOSURE_MASK, mini_maker);
	mlx_loop(game->mlx_ptr);
}

static int	valid_input(const char *argv)
{
	char	*str;

	if (count_char(argv, '.') != 1)
		return (0);
	str = ft_strrchr(argv, '.');
	if (str)
		return (ft_strcmp(str, ".ber") == 0);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_game	game;

	if (!check_env(envp) || !check_env2(envp))
		end_game("No env !", &game, env_error);
	if (argc == 2 && !(valid_input(argv[1])))
		end_game("Error format", &game, error);
	else if (argc > 2)
		end_game("Error multiple files", &game, error);
	else if (argc == 2 && valid_input(argv[1]))
		init_game(&game, argv[1]);
	end_game("File error", &game, error);
	return (0);
}
