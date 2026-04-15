/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_components.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 16:03:53 by mwin              #+#    #+#             */
/*   Updated: 2025/08/08 11:47:03 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	components_exist(char **map)
{
	int	row;
	int	column;

	row = 0;
	if (!map || !map[0])
		return (error_message("Empty map"), 0);
	while (map[row])
	{
		column = 0;
		while (map[row][column])
		{
			if (map[row][column] != '0' && map[row][column] != '1' &&
				map[row][column] != 'C' && map[row][column] != 'E' &&
				map[row][column] != 'P' && map[row][column] != '\n')
			{
				error_message("Invalid map components");
				return (0);
			}
			column++;
		}
		row++;
	}
	return (1);
}

static int	component_check(int count_p, int count_e, int count_c)
{
	if (count_p != 1)
	{
		error_message("There must only be 1 starting position");
		return (0);
	}
	if (count_e != 1)
	{
		error_message("There must only be 1 exit");
		return (0);
	}
	if (count_c < 1)
	{
		error_message("There must be at least 1 collectible");
		return (0);
	}
	return (1);
}

int	check_count(char **map)
{
	int	row;
	int	column;
	int	count_p;
	int	count_e;
	int	count_c;

	row = 0;
	count_c = 0;
	count_p = 0;
	count_e = 0;
	while (map[row])
	{
		column = -1;
		while (map[row][++column])
		{
			if (map[row][column] == 'P')
				count_p++;
			else if (map[row][column] == 'E')
				count_e++;
			else if (map[row][column] == 'C')
				count_c++;
		}
		row++;
	}
	return (component_check(count_p, count_e, count_c));
}
