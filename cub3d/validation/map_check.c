/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 19:10:00 by smariapp          #+#    #+#             */
/*   Updated: 2026/04/13 19:36:39 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// fl: f->0 l->1
int	first_and_last(int k, t_params *par, int fl)
{
	int		i;
	char	*line;

	i = 0;
	line = par->map[k];
	while (line[i] && (line[i] == '1' || line[i] == ' '))
	{
		if (line[i] == ' ' && check_leaky(i, k, par, !fl))
			return (0);
		i++;
	}
	if (line[i] == '\n' || line[i] == '\0')
		return (1);
	return (0);
}

void	check_ends(char *line, t_params *par)
{
	char	*trim;

	trim = ft_strtrim(par->map[i], " \n");
	if (trim[0] != '1' || trim[ft_strlen(trim) - 1] != '1')
		return (printf("Error\nInvalid Map - Unbounded\n"), \
free_params(par), exit(1), 0);
	free(trim);
}

int	middle(int i, t_params *par)
{
	int		leak;
	char	*line;

	line = par->map[i];
	check_ends(line, par);
	while (*line)
	{
		if ((*line == 'N' || *line == 'S' || *line == 'E' || *line == 'W') \
&& par->dir == 0)
			par->dir = *line;
		else if ((*line == 'N' || *line == 'S' || *line == 'E' || \
*line == 'W') && par->dir != 0)
			return (printf("Error\nInvalid Map - Multiple players\n"), \
free_params(par), exit(1), 0);
		else if (*line == ' ')
		{
			leak = check_leaky(line - par->map[i], i, par, 1);
			if (leak)
				return (printf("Error\nInvalid Map1\n"), \
free_params(par), exit(1), 0);
		}
		else if (*line == '0' && !check_zero(line - par->map[i], i, par))
			return (printf("Error\nInvalid Map4\n"), \
free_params(par), exit(1), 0);
		else if (*line != '1' && *line != '0' && *line != '\n')
			return (printf("Error\nInvalid Map2\n"), \
free_params(par), exit(1), 0);
		line++;
	}
	return (1);
}

char	**map_create(t_list *file)
{
	int		len;
	char	**map;
	int		i;

	while (file && identifier(file->content) != 4)
		file = file->next;
	len = map_s(file);
	map = (char **)malloc(sizeof(char *) * (len + 1));
	i = 0;
	while (file && i < len)
	{
		map[i] = ft_strdup(file->content);
		file = file->next;
		i++;
	}
	map[len] = NULL;
	return (map);
}

int	map_check(t_params *par)
{
	int		len;
	int		i;

	len = ft_arrlen(par->map);
	if (len < 3)
		return (printf("Error\nInvalid Map\n"), free_params(par), exit(1), 0);
	if (!first_and_last(0, par, 0))
		return (printf("Error\nInvalid Map - First Row\n"), free_params(par), \
exit(1), 0);
	i = 1;
	while (i < len - 1)
	{
		middle(i, par);
		i++;
	}
	if (!first_and_last(len - 1, par, 1))
		return (printf("Error\nInvalid Map - Last row\n"), free_params(par), \
exit(1), 0);
	if (!par->dir)
		return (printf("Error\nInvalid Map - No player\n"), free_params(par), \
exit(1), 0);
	return (1);
}
