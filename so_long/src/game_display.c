/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 11:41:05 by mwin              #+#    #+#             */
/*   Updated: 2025/08/09 15:27:12 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*show_correct_tiles(t_game *game, char tile)
{
	if (tile == '1')
		return (game->wall);
	if (tile == '0')
		return (game->floor);
	if (tile == 'P')
		return (game->avatar);
	if (tile == 'C')
		return (game->collectible);
	if (tile == 'E')
		return (game->exit);
	error_message("Unknown tile\n");
	return (NULL);
}

static void	visible_tiles(t_game *game, void *image, int y, int x)
{
	int	draw_x;
	int	draw_y;

	draw_x = (x - (game->frame_lft)) * game->sizeof_tile;
	draw_y = (y - (game->frame_tp)) * game->sizeof_tile;
	mlx_put_image_to_window(game->mlx, game->window,
		image, draw_x, draw_y);
}

void	display_map(t_game *game)
{
	int		y;
	int		x;
	char	tile;
	void	*image;

	y = game->frame_tp;
	while (y < (game->frame_tp + game->frame_btm))
	{
		x = game->frame_lft;
		while (x < (game->frame_lft + game->frame_rght))
		{
			tile = game->map[y][x];
			image = show_correct_tiles(game, tile);
			if (image)
				visible_tiles(game, image, y, x);
			x++;
		}
		y++;
	}
}
