/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_wall_shape.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 15:49:59 by mwin              #+#    #+#             */
/*   Updated: 2025/08/07 16:43:09 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_rectangle(char **map)
{
	int	row;
	int	column;
	int	len_if_rectangle;

	if (!map || !map[0])
		return (error_message("Nothing in map"), 0);
	len_if_rectangle = 0;
	while (map[0][len_if_rectangle])
		len_if_rectangle++;
	row = 0;
	while (map[row])
	{
		column = 0;
		while (map[row][column])
			column++;
		if (column != len_if_rectangle)
			return (error_message("Map is not rectangular"), 0);
		row++;
	}
	return (1);
}

static int	check_tp_btm(char **map, int n_columns, int n_rows)
{
	int	x;

	x = 0;
	while (x < n_columns)
	{
		if (map[0][x] != '1')
			return (error_message("Top wall invalid"), 0);
		x++;
	}
	x = 0;
	while (x < n_columns)
	{
		if (map[n_rows - 1][x] != '1')
			return (error_message("Bottom wall invalid"), 0);
		x++;
	}
	return (1);
}

int	check_fullwall(char **map)
{
	int		y;
	int		n_rows;
	int		n_columns;

	y = 0;
	n_columns = 0;
	while (map[y])
		y++;
	n_rows = y;
	while (map[0][n_columns])
		n_columns++;
	if (!check_tp_btm(map, n_columns, n_rows))
		return (0);
	y = 1;
	while (y < (n_rows - 1))
	{
		if (map[y][0] != '1' || map[y][n_columns - 1] != '1')
			return (error_message("Side walls invalid"), 0);
		y++;
	}
	return (1);
}
