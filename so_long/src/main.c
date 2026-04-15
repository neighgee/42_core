/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 12:14:35 by mwin              #+#    #+#             */
/*   Updated: 2025/08/11 14:48:26 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_map(char **map)
{
	if (!components_exist(map))
		return (0);
	if (!check_count(map))
		return (0);
	if (!is_rectangle(map))
		return (0);
	if (!check_fullwall(map))
		return (0);
	if (!check_path(map))
		return (0);
	return (1);
}

int	check_ber(char *filename)
{
	int	len_file;

	len_file = ft_strlen(filename);
	if (len_file < 5
		|| ft_strncmp(filename + len_file - 4, ".ber", 4) != 0)
	{
		error_message("Must have .ber extension");
		return (0);
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	char	**map;
	t_game	game;

	if (argc != 2)
	{
		error_message("Wrong number of arguments");
		return (1);
	}
	if (!check_ber(argv[1]))
		return (1);
	map = check_map(argv[1]);
	if (!map)
		return (1);
	if (!valid_map(map))
	{
		free_map(map);
		return (1);
	}
	initialise_game_display(&game, map);
	display_map(&game);
	listen_to_events(&game);
	free_map(map);
	return (0);
}
