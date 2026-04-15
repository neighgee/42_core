/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_colours.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 14:36:03 by mwin              #+#    #+#             */
/*   Updated: 2026/04/09 14:39:22 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//colour_minimap & colour_player are exactly the same
//only the delimiter is different

/* Function initiates all the pixels required to show game
This means it initiates: map & player */
int	init_game(t_game *game)
{
	init_map(game);
	if (!init_player(game))
		return (0);
	return (1);
}

/* Function does the below:
1. Finds the exact memory address of the pixel
2. Replace the value found at that address to the correct colour
(Maybe there could be a diff colour originally at the addr) */
void	colour_pixels(t_screen *screen, int x, int y, int colour)
{
	char	*pixel;

	if (x < 0 || y < 0)
		return ;
	pixel = screen->addr + (y * screen->b_perline + x * (screen->bpp / 8));
	*(unsigned int *)pixel = colour;
}

/* Function uses colour_pixels to colour a tile/square of pixels */
void	colour_minimap(t_game *game, int firstx, int firsty, int colour)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->mini_map.tile_size)
	{
		x = 0;
		while (x < game->mini_map.tile_size)
		{
			colour_pixels(&game->screen, firstx + x, firsty + y, colour);
			x++;
		}
		y++;
	}
}

/* Function uses colour_pixels to colour a tile/square of pixels */
void	colour_player(t_game *game, int firstx, int firsty, int colour)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->mini_map.player_pixel)
	{
		x = 0;
		while (x < game->mini_map.player_pixel)
		{
			colour_pixels(&game->screen, firstx + x, firsty + y, colour);
			x++;
		}
		y++;
	}
}

/* Function does the below:
1. Find the first half of window, colours it as ceiling
2. The rest is coloured as floor
3. Walls will be coloured after this */
void	colour_f_c(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->win_height)
	{
		x = 0;
		while (x < game->win_width && game->par->colours)
		{
			if (y < (game->win_height / 2))
				colour_pixels(&game->screen, x, y, game->par->ceil);
			else
				colour_pixels(&game->screen, x, y, game->par->floor);
			x++;
		}
		y++;
	}
}
