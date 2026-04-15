/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 15:01:27 by mwin              #+#    #+#             */
/*   Updated: 2026/04/11 19:40:31 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* mlx_xpm_file_to_image: opens the xpm file and creates an image you need */
void	create_textures(t_game *game, t_textures *tex, char *path)
{
	path[ft_strlen(path) - 1] = '\0';
	tex->img = mlx_xpm_file_to_image(game->mlx, path,
			&tex->width, &tex->height);
	if (!tex->img)
	{
		free_params(game->par);
		write(2, "Error\n Texture load failed\n", 27);
		exit(1);
	}
	tex->addr = mlx_get_data_addr(tex->img, &tex->bpp,
			&tex->b_perline, &tex->endian);
	if (!tex->addr)
	{
		free_params(game->par);
		write(2, "Error\n Texture address failed\n", 30);
		exit(1);
	}
}
