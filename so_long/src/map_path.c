/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:44:33 by mwin              #+#    #+#             */
/*   Updated: 2025/08/11 15:13:15 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_point	locate_avatar(char **map)
{
	t_point	avatar;
	int		y;
	int		x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				avatar.x = x;
				avatar.y = y;
				return (avatar);
			}
			x++;
		}
		y++;
	}
	avatar.x = -1;
	avatar.y = -1;
	return (avatar);
}

static void	flood(char **map, t_point avatar, int *is_exit)
{
	t_point	size;

	size.y = 0;
	while (map[size.y])
		size.y++;
	size.x = ft_strlen(map[0]);
	if (avatar.x < 0 || avatar.y < 0 || avatar.y >= size.y
		|| avatar.x >= size.x)
		return ;
	if (map[avatar.y][avatar.x] == 'F' || map[avatar.y][avatar.x] == '1')
		return ;
	if (map[avatar.y][avatar.x] == 'E')
	{
		*is_exit = 1;
		map[avatar.y][avatar.x] = 'F';
		return ;
	}
	map[avatar.y][avatar.x] = 'F';
	flood(map, (t_point){avatar.x + 1, avatar.y}, is_exit);
	flood(map, (t_point){avatar.x - 1, avatar.y}, is_exit);
	flood(map, (t_point){avatar.x, avatar.y + 1}, is_exit);
	flood(map, (t_point){avatar.x, avatar.y - 1}, is_exit);
}

static int	check_reachable(char **flooded)
{
	int	x;
	int	y;

	y = 0;
	while (flooded[y])
	{
		x = 0;
		while (flooded[y][x])
		{
			if (flooded[y][x] == 'C')
			{
				error_message("Collectibles are not reachable");
				return (0);
			}
			if (flooded[y][x] == 'E')
			{
				error_message("Exit is not reachable");
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

static int	validate_path(int *is_exit, t_point avatar, char **duplicate)
{
	flood(duplicate, avatar, is_exit);
	if (!*is_exit)
	{
		error_message("Exit is not reachable");
		return (0);
	}
	if (!check_reachable(duplicate))
		return (0);
	return (1);
}

int	check_path(char **map)
{
	t_point	avatar;
	char	**duplicate;
	int		is_exit;
	int		valid_path;

	is_exit = 0;
	avatar = locate_avatar(map);
	if (avatar.x == -1 || avatar.y == -1)
		return (error_message("Avatar lost"), 0);
	duplicate = duplicate_map(map);
	if (!duplicate)
	{
		error_message("Malloc failed");
		return (0);
	}
	valid_path = validate_path(&is_exit, avatar, duplicate);
	free_map(duplicate);
	if (!valid_path)
		return (0);
	return (1);
}
