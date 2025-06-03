/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machouba <machouba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:51:41 by machouba          #+#    #+#             */
/*   Updated: 2024/05/09 13:39:25 by machouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_game *game)
{
	while (game->plot.height > 0)
	{
		free(game->plot.map[game->plot.height - 1]);
		game->plot.height--;
	}
	free(game->plot.map);
	return ;
}

int	check_env(char **envp)
{
	const char	*env;
	char		*val_va;
	int			i;

	env = "USER";
	val_va = NULL;
	i = 0;
	while (envp[i])
	{
		if (ft_strstr(envp[i], (char *)env) == envp[i])
		{
			val_va = ft_strchr(envp[i], '=') + 1;
			break ;
		}
		i++;
	}
	if (val_va == NULL)
		return (0);
	else
		return (1);
}

void	kill_image2(t_game *game)
{
	if (game)
	{
		if (game->player_left.ptr)
			mlx_destroy_image(game->mlx_ptr, game->player_left.ptr);
		if (game->player_right.ptr)
			mlx_destroy_image(game->mlx_ptr, game->player_right.ptr);
		if (game->player_upper.ptr)
			mlx_destroy_image(game->mlx_ptr, game->player_upper.ptr);
		mlx_destroy_window(game->mlx_ptr, game->windows_ptr);
		mlx_destroy_display(game->mlx_ptr);
		free_map(game);
		free(game->mlx_ptr);
	}
	return ;
}

void	kill_image(t_game *game)
{
	if (game)
	{
		if (game->wall.ptr)
			mlx_destroy_image(game->mlx_ptr, game->wall.ptr);
		if (game->floor.ptr)
			mlx_destroy_image(game->mlx_ptr, game->floor.ptr);
		if (game->item.ptr)
			mlx_destroy_image(game->mlx_ptr, game->item.ptr);
		if (game->dj_close.ptr)
			mlx_destroy_image(game->mlx_ptr, game->dj_close.ptr);
		if (game->dj_open.ptr)
			mlx_destroy_image(game->mlx_ptr, game->dj_open.ptr);
		if (game->player.ptr)
			mlx_destroy_image(game->mlx_ptr, game->player.ptr);
		kill_image2(game);
	}
	return ;
}

void	end_game(char *message, t_game *game, enum e_state i)
{
	if (i == env_error || i == error || i == file_error)
	{
		ft_printf("Error\n%s\n", message);
		exit(1);
	}
	else if (i == image_error)
	{
		ft_printf("Error\n%s\n", message);
		kill_image(game);
		exit(1);
	}
	else if (i == map_char_error || i == design_map_error)
	{
		free_map(game);
		ft_printf("Error\n%s\n", message);
		exit(1);
	}
	else if (i == event_end || i == game_over)
	{
		ft_printf("%s\n", message);
		kill_image(game);
		exit(0);
	}
	end_game2(message, game);
}
