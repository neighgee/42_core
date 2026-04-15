/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 12:30:03 by mwin              #+#    #+#             */
/*   Updated: 2026/04/09 14:19:52 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Function does the below:
1. finds the starting x pixel & y pixel using screen_x & screen_y
2. draws the minimap tiles using colour tiles */
void	create_minimap(t_game *game)
{
	int	x;
	int	y;
	int	firstx;
	int	firsty;
	int	colour;

	y = 0;
	if (game->mini_map.tile_size <= 0)
		return ;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			firstx = game->mini_map.first_x + x * game->mini_map.tile_size;
			firsty = game->mini_map.first_y + y * game->mini_map.tile_size;
			if (game->map.map[y][x] == '1')
				colour = game->mini_map.wall_c;
			else
				colour = game->mini_map.floor_c;
			colour_minimap(game, firstx, firsty, colour);
			x++;
		}
		y++;
	}
}

/* Function does the below:
1. finds the starting x pixel(playerx) & y pixel(playery)
2. draws the minimap tiles using colour tiles
3. makes sure player is at the centre of the tile using "size/2" */
void	position_player(t_game *game)
{
	int	playerx;
	int	playery;
	int	size;

	if (game->mini_map.player_pixel <= 0)
		return ;
	size = game->mini_map.player_pixel;
	playerx = game->mini_map.first_x + (int)(game->player.playerx
			* game->mini_map.tile_size);
	playery = game->mini_map.first_y + (int)(game->player.playery
			* game->mini_map.tile_size);
	colour_player(game, playerx - size / 2, playery - size / 2,
		game->mini_map.player_c);
}

/* Function is a helper to draw direction line */
static void	create_line(t_game *game, int start_x, int start_y)
{
	int	i;
	int	x;
	int	y;
	int	end_x;
	int	end_y;

	end_x = start_x + (int)(game->player.dir_x * game->mini_map.tile_size);
	end_y = start_y + (int)(game->player.dir_y * game->mini_map.tile_size);
	i = 0;
	while (i <= game->mini_map.tile_size)
	{
		x = start_x + (end_x - start_x) * i / game->mini_map.tile_size;
		y = start_y + (end_y - start_y) * i / game->mini_map.tile_size;
		colour_pixels(&game->screen, x, y, game->mini_map.dir_c);
		i++;
	}
}

void	show_dir(t_game *game)
{
	int	start_x;
	int	start_y;

	if (game->mini_map.tile_size <= 0)
		return ;
	start_x = game->mini_map.first_x + (int)(game->player.playerx
			* game->mini_map.tile_size);
	start_y = game->mini_map.first_y + (int)(game->player.playery
			* game->mini_map.tile_size);
	create_line(game, start_x, start_y);
}

void	minimap(t_game *game)
{
	create_minimap(game);
	position_player(game);
	show_dir(game);
}
