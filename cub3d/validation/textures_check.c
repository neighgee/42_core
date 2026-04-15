/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 19:10:04 by smariapp          #+#    #+#             */
/*   Updated: 2026/04/09 19:15:56 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//check if the texture exists and has permissions /
//check texture file type /
//check if there are multiple textures for a single cardinality /

//assume that it is a valid label when it gets here

#include "cub3d.h"

void	assign_texture_path(t_params *par, char **split, int fd)
{
	if (!ft_strncmp(split[0], "NO", 3) && !par->n)
		par->n = ft_strdup(split[1]);
	else if (!ft_strncmp(split[0], "SO", 3) && !par->s)
		par->s = ft_strdup(split[1]);
	else if (!ft_strncmp(split[0], "EA", 3) && !par->e)
		par->e = ft_strdup(split[1]);
	else if (!ft_strncmp(split[0], "WE", 3) && !par->w)
		par->w = ft_strdup(split[1]);
	else
	{
		free_params(par);
		free_arr(split);
		close(fd);
		printf("Error\nInvalid File Type(Texture)\n");
		exit(1);
	}
	close(fd);
}

void	check_textures(char *str, t_params *par)
{
	char	**split;
	int		ret;
	int		fd;

	split = ft_split(str, ' ');
	ret = check_file_type(split[1], ".xpm");
	if (!ret)
	{
		free_params(par);
		free_arr(split);
		write(2, "Error\nInvalid File Type(Texture)\n", 33);
		exit(1);
	}
	fd = gimme_fd(split[1]);
	if (fd < 0)
	{
		free_arr(split);
		free_params(par);
		write(2, "Error\nInvalid File(Texture)\n", 28);
		exit(1);
	}
	assign_texture_path(par, split, fd);
	if (par->n && par->s && par->e && par->w)
		par->textures = 1;
	free_arr(split);
}
