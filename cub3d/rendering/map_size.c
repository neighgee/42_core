/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 12:30:01 by mwin              #+#    #+#             */
/*   Updated: 2026/04/11 20:29:37 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	map_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

/*Function checks strlen of each y then
finds the longest string and returns its length*/
static int	map_width(char **map)
{
	int	i;
	int	max;
	int	len;

	i = 0;
	max = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (map[i][len - 1] == '\n')
			len--;
		if (len > max)
			max = len;
		i++;
	}
	return (max);
}

void	init_map(t_game *game)
{
	game->map.map = game->par->map;
	game->map.height = map_height(game->par->map);
	game->map.width = map_width(game->par->map);
}

void	init_minimap(t_game *game)
{
	game->mini_map.first_x = 20;
	game->mini_map.first_y = 20;
	game->mini_map.tile_size = 10;
	game->mini_map.player_pixel = 4;
	game->mini_map.wall_c = 0x00FFFFFF;
	game->mini_map.floor_c = 0x00333333;
	game->mini_map.player_c = 0x00FF0000;
	game->mini_map.dir_c = 0x0000FF00;
}
