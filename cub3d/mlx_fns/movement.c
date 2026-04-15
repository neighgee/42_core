/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 10:56:12 by mwin              #+#    #+#             */
/*   Updated: 2026/04/09 19:38:44 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define ESC_KEY 65307
#define W_KEY 119
#define A_KEY 97
#define S_KEY 115
#define D_KEY 100
#define LEFT_KEY 65361
#define RIGHT_KEY 65363

static int	key_press(int keycode, t_game *game)
{
	if (keycode == ESC_KEY)
		return (quit_program(game));
	else if (keycode == W_KEY)
		game->keys.w = 1;
	else if (keycode == A_KEY)
		game->keys.a = 1;
	else if (keycode == S_KEY)
		game->keys.s = 1;
	else if (keycode == D_KEY)
		game->keys.d = 1;
	else if (keycode == LEFT_KEY)
		game->keys.left = 1;
	else if (keycode == RIGHT_KEY)
		game->keys.right = 1;
	return (0);
}

static int	key_letgo(int keycode, t_game *game)
{
	if (keycode == W_KEY)
		game->keys.w = 0;
	else if (keycode == A_KEY)
		game->keys.a = 0;
	else if (keycode == S_KEY)
		game->keys.s = 0;
	else if (keycode == D_KEY)
		game->keys.d = 0;
	else if (keycode == LEFT_KEY)
		game->keys.left = 0;
	else if (keycode == RIGHT_KEY)
		game->keys.right = 0;
	return (0);
}

/* Mlx_put_image_to_window: Displays screen/images visibly
(without this you will just be editing the memory) */
static int	display_screen(t_game *game)
{
	walk_updown(game);
	turn_sideway(game);
	colour_f_c(game);
	raycasting(game);
	mlx_put_image_to_window(game->mlx, game->win, game->screen.img, 0, 0);
	return (0);
}

/* Mlx hook: Registers events (eg. w is pressed/letgo)
Mlx loop hook: Registers event that runs as loop
Mlx loop: starts the actual loop/starts game screen

listen_to_events() takes care of free-ing via:
-quit_program
-clean_program */
void	listen_to_events(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, key_press, game);
	mlx_hook(game->win, 3, 1L << 1, key_letgo, game);
	mlx_hook(game->win, 17, 0, quit_program, game);
	mlx_loop_hook(game->mlx, display_screen, game);
	mlx_loop(game->mlx);
}
