/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 10:03:50 by mwin              #+#    #+#             */
/*   Updated: 2026/04/09 15:51:36 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Mlx_new_window: creates a new window
Mlx_new_image: Creates an image buffer (off-screen)
Mls_get_data_addr lets you get the address of the screen's pixels */
int	init_win(t_game *game)
{
	game->win_width = 1920;
	game->win_height = 768;
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	init_textures(game);
	game->win = mlx_new_window(game->mlx, game->win_width,
			game->win_height, "cub3d");
	if (!game->win)
		return (0);
	game->screen.img = mlx_new_image(game->mlx, game->win_width,
			game->win_height);
	if (!game->screen.img)
		return (0);
	game->screen.addr = mlx_get_data_addr(game->screen.img, &game->screen.bpp,
			&game->screen.b_perline, &game->screen.endian);
	if (!game->screen.addr)
		return (0);
	return (1);
}
