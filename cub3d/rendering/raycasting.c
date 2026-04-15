/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 17:00:04 by mwin              #+#    #+#             */
/*   Updated: 2026/04/09 14:38:47 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ray_dir(t_game *game, int x)
{
	game->ray.r_vs_cam = (2.0 * (x / (double)game->win_width)) - 1.0;
	game->ray.ray_dirx = game->player.dir_x + game->player.cam_x
		* game->ray.r_vs_cam;
	game->ray.ray_diry = game->player.dir_y + game->player.cam_y
		* game->ray.r_vs_cam;
	game->ray.map_x = (int)game->player.playerx;
	game->ray.map_y = (int)game->player.playery;
	if (game->ray.ray_dirx == 0)
		game->ray.deltadistx = 1e30;
	else
		game->ray.deltadistx = fabs(1.0 / game->ray.ray_dirx);
	if (game->ray.ray_diry == 0)
		game->ray.deltadisty = 1e30;
	else
		game->ray.deltadisty = fabs(1.0 / game->ray.ray_diry);
	game->ray.wall = 0;
}

void	ray_movements(t_game *game)
{
	if (game->ray.ray_dirx < 0)
	{
		game->ray.step_x = -1;
		game->ray.total_x = (game->player.playerx - game->ray.map_x)
			* game->ray.deltadistx;
	}
	else
	{
		game->ray.step_x = 1;
		game->ray.total_x = (game->ray.map_x - game->player.playerx + 1.0)
			* game->ray.deltadistx;
	}
	if (game->ray.ray_diry < 0)
	{
		game->ray.step_y = -1;
		game->ray.total_y = (game->player.playery - game->ray.map_y)
			* game->ray.deltadisty;
	}
	else
	{
		game->ray.step_y = 1;
		game->ray.total_y = (game->ray.map_y - game->player.playery + 1.0)
			* game->ray.deltadisty;
	}
}

void	step_till_wall(t_game *game)
{
	while (game->ray.wall == 0)
	{
		if (game->ray.total_x < game->ray.total_y)
		{
			game->ray.total_x += game->ray.deltadistx;
			game->ray.map_x += game->ray.step_x;
			game->ray.hit_y = 0;
		}
		else
		{
			game->ray.total_y += game->ray.deltadisty;
			game->ray.map_y += game->ray.step_y;
			game->ray.hit_y = 1;
		}
		if (game->map.map[game->ray.map_y][game->ray.map_x] == '1')
			game->ray.wall = 1;
	}
}

void	init_wall(t_game *game)
{
	if (game->ray.hit_y == 0)
		game->ray.perpwalldist = game->ray.total_x - game->ray.deltadistx;
	else
		game->ray.perpwalldist = game->ray.total_y - game->ray.deltadisty;
	game->wall.wallheight = (int)(game->win_height / game->ray.perpwalldist);
	game->wall.topypixel = (game->win_height - game->wall.wallheight) / 2;
	if (game->wall.topypixel < 0)
		game->wall.topypixel = 0;
	game->wall.endypixel = (game->win_height + game->wall.wallheight) / 2;
	if (game->wall.endypixel >= game->win_height)
		game->wall.endypixel = game->win_height - 1;
}

void	raycasting(t_game *game)
{
	int	x;

	x = 0;
	while (x < game->win_width)
	{
		ray_dir(game, x);
		ray_movements(game);
		step_till_wall(game);
		init_wall(game);
		draw_wall(game, x);
		x++;
	}
}
