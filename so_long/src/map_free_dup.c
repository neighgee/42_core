/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:36:07 by mwin              #+#    #+#             */
/*   Updated: 2025/08/08 11:47:10 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// use before program exit or before loading a new map
void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

static void	free_dup_fail(char **duplicate, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free(duplicate[j]);
		j++;
	}
	free(duplicate);
}

char	**duplicate_map(char **map)
{
	char	**duplicate;
	int		i;

	i = 0;
	while (map[i])
		i++;
	duplicate = malloc(sizeof(char *) * (i + 1));
	if (!duplicate)
		return (NULL);
	i = 0;
	while (map[i])
	{
		duplicate[i] = ft_strdup(map[i]);
		if (!duplicate[i])
		{
			free_dup_fail(duplicate, i);
			return (NULL);
		}
		i++;
	}
	duplicate[i] = NULL;
	return (duplicate);
}
