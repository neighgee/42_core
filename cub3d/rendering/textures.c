/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 15:25:33 by mwin              #+#    #+#             */
/*   Updated: 2026/04/09 15:41:11 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_textures(t_game *game)
{
	create_textures(game, &game->n, game->par->n);
	create_textures(game, &game->s, game->par->s);
	create_textures(game, &game->e, game->par->e);
	create_textures(game, &game->w, game->par->w);
}

int	return_pixel_colour(t_textures	*tex, int x, int y)
{
	char	*pixel;

	pixel = tex->addr + (y * tex->b_perline + x * (tex->bpp / 8));
	return (*(unsigned int *)pixel);
}

t_textures	*choose_texture(t_game *game)
{
	if (game->ray.hit_y)
	{
		if (game->ray.ray_diry > 0)
			return (&game->s);
		return (&game->n);
	}
	else
	{
		if (game->ray.ray_dirx > 0)
			return (&game->e);
		return (&game->w);
	}
}

int	find_tex_x(t_game *game, t_textures *tex)
{
	double	wall_x;
	int		tex_x;

	if (game->ray.hit_y == 1)
		wall_x = game->player.playerx + game->ray.perpwalldist
			* game->ray.ray_dirx;
	else
		wall_x = game->player.playery + game->ray.perpwalldist
			* game->ray.ray_diry;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)tex->width);
	if (game->ray.hit_y == 0 && game->ray.ray_dirx > 0)
		tex_x = tex->width - tex_x - 1;
	if (game->ray.hit_y == 1 && game->ray.ray_diry < 0)
		tex_x = tex->width - tex_x - 1;
	return (tex_x);
}
