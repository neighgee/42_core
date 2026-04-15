/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 16:15:08 by smariapp          #+#    #+#             */
/*   Updated: 2026/04/09 14:05:49 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* listen_to_events() takes care of free-ing via:
1. quit_program
2. clean_program */
void	initialise(t_game *game)
{
	if (!init_win(game))
	{
		write(2, "Error\nMLX init failed\n", 22);
		free_params(game->par);
		exit(1);
	}
	if (!init_game(game))
	{
		write(2, "Error\nGame startup failed\n", 26);
		clean_program(game);
		exit (1);
	}
	init_minimap(game);
	listen_to_events(game);
}

//parse_file takes care of exiting if invalid
int	main(int argc, char **argv)
{
	int			fd;
	int			ret;
	t_game		game;

	ft_memset(&game, 0, sizeof(t_game));
	if (argc != 2)
	{
		write(2, "Error\nInvalid Argument(s)\n", 26);
		exit(1);
	}
	ret = check_file_type(argv[1], ".cub");
	if (!ret)
	{
		write(2, "Error\nInvalid File Type(input file)\n", 36);
		exit(1);
	}
	fd = gimme_fd(argv[1]);
	game.par = parse_file(fd);
	initialise(&game);
	return (0);
}
