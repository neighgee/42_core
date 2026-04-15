/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 13:47:46 by mwin              #+#    #+#             */
/*   Updated: 2025/08/11 11:25:45 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	listen_to_events(t_game *game)
{
	mlx_hook(game->window, 2, 1L << 0, move_avatar, game);
	mlx_hook(game->window, 17, 0, quit_program, game);
	mlx_loop(game->mlx);
}

void	clean_program(t_game *game)
{
	if (game->mlx)
	{
		if (game->wall)
			mlx_destroy_image(game->mlx, game->wall);
		if (game->floor)
			mlx_destroy_image(game->mlx, game->floor);
		if (game->avatar)
			mlx_destroy_image(game->mlx, game->avatar);
		if (game->collectible)
			mlx_destroy_image(game->mlx, game->collectible);
		if (game->exit)
			mlx_destroy_image(game->mlx, game->exit);
		if (game->window)
		{
			mlx_clear_window(game->mlx, game->window);
			mlx_destroy_window(game->mlx, game->window);
		}
	}
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	if (game->map)
		free_map(game->map);
}

int	quit_program(t_game *game)
{
	clean_program(game);
	exit(0);
	return (0);
}
