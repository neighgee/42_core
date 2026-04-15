/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 10:39:11 by mwin              #+#    #+#             */
/*   Updated: 2026/04/09 16:11:57 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clean_program(t_game *game)
{
	if (game->mlx)
	{
		if (game->screen.img)
			mlx_destroy_image(game->mlx, game->screen.img);
		if (game->n.img)
			mlx_destroy_image(game->mlx, game->n.img);
		if (game->s.img)
			mlx_destroy_image(game->mlx, game->s.img);
		if (game->e.img)
			mlx_destroy_image(game->mlx, game->e.img);
		if (game->w.img)
			mlx_destroy_image(game->mlx, game->w.img);
		if (game->win)
		{
			mlx_clear_window(game->mlx, game->win);
			mlx_destroy_window(game->mlx, game->win);
		}
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (game->par)
		free_params(game->par);
}

int	quit_program(t_game *game)
{
	clean_program(game);
	exit(0);
	return (0);
}
