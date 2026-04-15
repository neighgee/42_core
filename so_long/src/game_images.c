/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 13:35:26 by mwin              #+#    #+#             */
/*   Updated: 2025/08/11 14:53:00 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	frame_avatar(t_game *game)
{
	int	map_x;
	int	map_y;

	map_x = ft_strlen(game->map[0]);
	map_y = 0;
	while (game->map[map_y])
		map_y++;
	game->frame_lft = game->avatar_x - game->frame_rght / 2;
	game->frame_tp = game->avatar_y - game->frame_btm / 2;
	if (game->frame_lft < 0)
		game->frame_lft = 0;
	if (game->frame_tp < 0)
		game->frame_tp = 0;
	if (((game->frame_lft) + (game->frame_rght) > map_x))
	{
		game->frame_lft = map_x - game->frame_rght;
		if (game->frame_lft < 0)
			game->frame_lft = 0;
	}
	if (((game->frame_tp) + (game->frame_btm) > map_y))
	{
		game->frame_tp = map_y - game->frame_btm;
		if (game->frame_tp < 0)
			game->frame_tp = 0;
	}
}

static void	avatar_adjust(char **map, t_game *game, int window_x, int window_y)
{
	t_point	avatar;

	avatar = locate_avatar(map);
	game->avatar_y = avatar.y;
	game->avatar_x = avatar.x;
	game->frame_rght = window_x / game->sizeof_tile;
	game->frame_btm = window_y / game->sizeof_tile;
	frame_avatar(game);
}

static int	resize_if_exceed(int x, int y, int *window_x, int *window_y)
{
	int		tile_size;
	float	scale_x;
	float	scale_y;
	float	scale;

	tile_size = 64;
	*window_x = x * tile_size;
	*window_y = y * tile_size;
	if (*window_x > 1800 || *window_y > 1000)
	{
		scale_x = (float)1800 / *window_x;
		scale_y = (float)1000 / *window_y;
		if (scale_x < scale_y)
			scale = scale_x;
		else
			scale = scale_y;
		tile_size = (int)(tile_size * scale);
		if (tile_size < 16)
			tile_size = 16;
		*window_x = x * tile_size;
		*window_y = y * tile_size;
	}
	return (tile_size);
}

static void	store_win_img(t_game *game, int window_x, int window_y)
{
	game->window = mlx_new_window(game->mlx, window_x, window_y, "so_long");
	if (!game->window)
		access_fail_exit("Window creation failed \n", game);
	game->wall = mlx_xpm_file_to_image(game->mlx, "src/textures/walls.xpm",
			&game->sizeof_tile, &game->sizeof_tile);
	if (!game->wall)
		access_fail_exit("Wall creation failed \n", game);
	game->floor = mlx_xpm_file_to_image(game->mlx, "src/textures/floor.xpm",
			&game->sizeof_tile, &game->sizeof_tile);
	if (!game->floor)
		access_fail_exit("Floor creation failed \n", game);
	game->avatar = mlx_xpm_file_to_image(game->mlx, "src/textures/avatar.xpm",
			&game->sizeof_tile, &game->sizeof_tile);
	if (!game->avatar)
		access_fail_exit("Avatar creation failed \n", game);
	game->collectible = mlx_xpm_file_to_image(game->mlx, "src/textures/C.xpm",
			&game->sizeof_tile, &game->sizeof_tile);
	if (!game->collectible)
		access_fail_exit("Collectible creation failed \n", game);
	game->exit = mlx_xpm_file_to_image(game->mlx, "src/textures/exit.xpm",
			&game->sizeof_tile, &game->sizeof_tile);
	if (!game->exit)
		access_fail_exit("Exit creation failed \n", game);
}

void	initialise_game_display(t_game *game, char **map)
{
	int	x;
	int	y;
	int	tile_size;
	int	window_x;
	int	window_y;

	window_x = 0;
	window_y = 0;
	tile_size = 64;
	y = 0;
	x = ft_strlen(map[0]);
	while (map[y])
		y++;
	tile_size = resize_if_exceed(x, y, &window_x, &window_y);
	game->movements = 0;
	game->sizeof_tile = tile_size;
	game->window_y = window_y;
	game->window_x = window_x;
	game->mlx = mlx_init();
	if (!game->mlx)
		access_fail_exit("MLX initialising failed \n", game);
	store_win_img(game, window_x, window_y);
	game->map = map;
	avatar_adjust(map, game, window_x, window_y);
}
