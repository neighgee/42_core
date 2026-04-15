/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 19:09:57 by smariapp          #+#    #+#             */
/*   Updated: 2026/04/08 15:55:49 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

//check if there are 3 num /
//check if within 0-255 for all /

int	ft_atoi_hue(const char *nptr)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	if (!*nptr || *nptr == '\n')
		return (-1);
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
		return (-1);
	while (*nptr >= '0' && *nptr <= '9' && result <= 255)
	{
		result = (result * 10) + *nptr - '0';
		nptr++;
	}
	if (result > 255)
		return (-1);
	while ((*nptr && ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')))
		nptr++;
	if (*nptr == '\0' || *nptr == '\n')
		return (sign * result);
	return (-1);
}
//will accept 00000, chnage to 0 and then trim + strncp later if need to change

// cf: 0 -> c, 1 -> f
void	check_colours(char *str, t_params *par, int cf)
{
	char	**rgb;
	int		i;
	int		hue;
	int		val[3];

	i = 0;
	str += 2;
	rgb = ft_split(str, ',');
	if (ft_arrlen(rgb) != 3)
		return (printf("Error\ninvalid color\n"), free_arr(rgb), \
free_params(par), exit(1));
	while (rgb[i])
	{
		hue = ft_atoi_hue(rgb[i]);
		if (hue < 0)
			return (printf("Error\ninvalid color\n"), free_arr(rgb), \
free_params(par), exit(1));
		val[i] = hue;
		i++;
	}
	if (!cf)
		par->ceil = val[0] << 16 | val[1] << 8 | val[2];
	else
		par->floor = val[0] << 16 | val[1] << 8 | val[2];
	if (par->ceil >= 0 && par->floor >= 0)
		par->colours = 1;
	free_arr(rgb);
}
