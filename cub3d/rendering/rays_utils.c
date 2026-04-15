/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 13:41:23 by mwin              #+#    #+#             */
/*   Updated: 2026/04/11 20:22:15 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	find_wallheight(t_game *game)
{
	return (game->wall.endypixel - game->wall.topypixel + 1);
}

void	texturise_wall(t_game *game, int x, t_textures *tex, int tex_x)
{
	int			y;
	int			tex_y;
	double		step;
	double		tex_pos;

	step = (double)tex->height / game->wall.wallheight;
	tex_pos = 0;
	y = game->wall.topypixel;
	while (y <= game->wall.endypixel)
	{
		tex_y = (int)tex_pos;
		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= tex->height)
			tex_y = tex->height - 1;
		colour_pixels(&game->screen, x, y,
			return_pixel_colour(tex, tex_x, tex_y));
		tex_pos += step;
		y++;
	}
}

void	draw_wall(t_game *game, int x)
{
	t_textures	*tex;
	int			tex_x;

	tex = choose_texture(game);
	tex_x = find_tex_x(game, tex);
	texturise_wall(game, x, tex, tex_x);
}

/* void	trim_newline(char *line)
{
	int	len;

	if (!line)
		return ;
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
} */
