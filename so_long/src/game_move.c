/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 12:39:25 by mwin              #+#    #+#             */
/*   Updated: 2025/08/11 15:01:58 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	moveable(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == '1')
		return (0);
	return (1);
}

static void	update_map_count_move(t_game *game, t_point position,
	int new_x, int new_y)
{
	game->map[position.y][position.x] = '0';
	if (game->map[new_y][new_x] != 'E')
	{
		game->map[new_y][new_x] = 'P';
		game->movements++;
	}
	ft_printf("Move Count: %d\n", game->movements);
	display_map(game);
}

static int	remaining_c(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

static void	before_quit(t_game *game, int new_x, int new_y, t_point position)
{
	if (game->map[new_y][new_x] == 'E')
	{
		if (remaining_c(game->map))
		{
			ft_printf("Collect all mushrooms!\n");
			return ;
		}
		else
		{
			ft_printf("You have collected all mushrooms!\n");
			quit_program(game);
		}
	}
	update_map_count_move(game, position, new_x, new_y);
	game->avatar_x = new_x;
	game->avatar_y = new_y;
	frame_avatar(game);
	display_map(game);
}

// 65307: ESC key
// 119/65362: W or UP keys
// 115/65364: S or DOWN keys
// 97/65361: A or LEFT keys
// 100/65363: A or RIGHT keys
int	move_avatar(int key, t_game *game)
{
	int		new_x;
	int		new_y;
	t_point	position;

	position = locate_avatar(game->map);
	new_x = position.x;
	new_y = position.y;
	if (key == 65307)
		quit_program(game);
	else if (key == 119 || key == 65362)
		new_y--;
	else if (key == 115 || key == 65364)
		new_y++;
	else if (key == 97 || key == 65361)
		new_x--;
	else if (key == 100 || key == 65363)
		new_x++;
	if ((new_x != position.x || new_y != position.y)
		&& moveable(game, new_x, new_y))
		before_quit(game, new_x, new_y, position);
	return (0);
}
