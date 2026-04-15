/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 20:21:07 by mwin              #+#    #+#             */
/*   Updated: 2026/04/13 19:35:03 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map_s(t_list *file)
{
	int	i;

	i = 0;
	while (file && identifier(file->content) == 4)
	{
		file = file->next;
		i++;
	}
	return (i);
}

//check for bounded
//check for non ' ', 1, 0, N, S, E, W
//check that there si only 1 cardinal sign / player start pos /

//i: index in the line
//k: line in map
//f: check line below -> yes for first
int	check_leaky(int i, int k, t_params *par, int f)
{
	char	*line;

	line = par->map[k];
	if (i > 0 && (line[i - 1] != '1' && line[i - 1] != ' '))
		return (1);
	if (line[k + 1] && line[i + 1] != '1' && line[i + 1] != ' ')
		return (1);
	if (f && par->map[k + 1][i] && (par->map[k + 1][i] != '1' \
&& par->map[k + 1][i] != ' '))
		return (1);
	if (k > 0 && par->map[k - 1][i] && (par->map[k - 1][i] != '1' \
&& par->map[k - 1][i] != ' '))
		return (1);
	return (0);
}

//i: index in the line
//k: line in map
//f: check line below -> yes for first
int	check_zero(int i, int k, t_params *par)
{
	char	*line;

	line = par->map[k];
	if ((int)ft_strlen(par->map[k - 1]) - 1 < i || \
(int)ft_strlen(par->map[k + 1]) - 1 < i || !line[i - 1] || \
!line[i + 1] || line[i + 1] == '\n')
		return (0);
	else
		return (1);
}
