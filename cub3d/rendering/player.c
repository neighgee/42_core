/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 12:31:28 by mwin              #+#    #+#             */
/*   Updated: 2026/04/09 20:05:40 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	orientate_updown(t_pov *player, char dir)
{
	if (dir == 'N')
	{
		player->dir_x = 0;
		player->dir_y = -1;
		player->cam_x = 0.66;
		player->cam_y = 0;
	}
	if (dir == 'S')
	{
		player->dir_x = 0;
		player->dir_y = 1;
		player->cam_x = -0.66;
		player->cam_y = 0;
	}
}

static void	orientate_sideway(t_pov *player, char dir)
{
	if (dir == 'E')
	{
		player->dir_x = 1;
		player->dir_y = 0;
		player->cam_x = 0;
		player->cam_y = 0.66;
	}
	if (dir == 'W')
	{
		player->dir_x = -1;
		player->dir_y = 0;
		player->cam_x = 0;
		player->cam_y = -0.66;
	}
}

int	init_player(t_game *game)
{
	int		x;
	int		y;
	char	c;

	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			c = game->map.map[y][x];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				game->player.playerx = x + 0.5;
				game->player.playery = y + 0.5;
				orientate_updown(&game->player, c);
				orientate_sideway(&game->player, c);
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

/* Function is not a simple up down, it calculates:
1. x & y according to the direction player faces
2. playerx & playery will be used to accurately move player on screen
because you need to account for the movement's x and y vectors
4. W means forward in terms of where he is facing, which is why "+"
5. D means backwards in terms of where he is facing, which is why "-" */
void	walk_updown(t_game *game)
{
	double	speed;
	double	buffer;

	speed = 0.08;
	buffer = 0.2;
	if (game->keys.w)
	{
		if (game->map.map[(int)game->player.playery][(int)(game->player.playerx
			+ game->player.dir_x * (speed + buffer))] != '1')
			game->player.playerx += game->player.dir_x * (speed);
		if (game->map.map[(int)(game->player.playery + game->player.dir_y
				* speed)][(int)game->player.playerx] != '1')
			game->player.playery += game->player.dir_y * speed;
	}
	if (game->keys.s)
	{
		if (game->map.map[(int)game->player.playery][(int)(game->player.playerx
			- game->player.dir_x * (speed + buffer))] != '1')
			game->player.playerx -= game->player.dir_x * (speed);
		if (game->map.map[(int)(game->player.playery - game->player.dir_y
				* speed)][(int)game->player.playerx] != '1')
			game->player.playery -= game->player.dir_y * speed;
	}
}

/* Function checks:
1. presets angle for turning
2. If left/right or a/d gets pressed:
	-calculate player's new x & y direction using the angle
	-calculate player's new camera direction using the angle */
void	turn_sideway(t_game *game)
{
	double	old_dir_x;
	double	old_cam_x;
	double	angle;

	angle = 0.02;
	if (game->keys.left || game->keys.a)
		angle = -angle;
	else if (!game->keys.right && !game->keys.d)
		return ;
	old_dir_x = game->player.dir_x;
	game->player.dir_x = game->player.dir_x * cos(angle)
		- game->player.dir_y * sin(angle);
	game->player.dir_y = old_dir_x * sin(angle)
		+ game->player.dir_y * cos(angle);
	old_cam_x = game->player.cam_x;
	game->player.cam_x = game->player.cam_x * cos(angle)
		- game->player.cam_y * sin(angle);
	game->player.cam_y = old_cam_x * sin(angle)
		+ game->player.cam_y * cos(angle);
}
