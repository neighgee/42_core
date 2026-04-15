/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 16:15:16 by smariapp          #+#    #+#             */
/*   Updated: 2026/04/11 20:21:59 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//if space check of around it is 1/' ' - for borders
//fist and last line only has 1 and ' '

#include "../cub3d.h"

int	empty_line(char *line)
{
	while ((*line >= 9 && *line <= 13) || *line == ' ')
		line++;
	if (*line == '\n' || *line == '\0')
		return (1);
	return (0);
}

int	identifier(char	*line)
{
	if (empty_line(line))
		return (0);
	if (!ft_strncmp(line, "NO ", 3) || !ft_strncmp(line, "SO ", 3) \
|| !ft_strncmp(line, "EA ", 3) || !ft_strncmp(line, "WE ", 3))
		return (1);
	if (!ft_strncmp(line, "C ", 2))
		return (2);
	if (!ft_strncmp(line, "F ", 2))
		return (3);
	while (*line)
	{
		if (*line == '0' || *line == '1' || *line == ' ' || *line == 'N' || \
*line == 'S' || *line == 'W' || *line == 'E')
			line++;
		else
			break ;
	}
	if (*line == '\n' || *line == '\0')
		return (4);
	return (-1);
}

t_list	*read_file(int fd)
{
	char	*line;
	t_list	*maplist;
	t_list	*prev;
	t_list	*head;

	line = get_next_line(fd, 0);
	prev = NULL;
	head = NULL;
	while (line)
	{
		maplist = malloc(sizeof(t_list));
		maplist->content = line;
		if (prev)
			prev->next = maplist;
		else
			head = maplist;
		prev = maplist;
		line = get_next_line(fd, 0);
	}
	if (prev)
		prev->next = NULL;
	return (head);
}

int	check_formatting(t_list *file, t_params *par)
{
	int	map;
	int	id;

	map = 0;
	while (file)
	{
		id = identifier(file->content);
		if (id == 0 && map)
			map = 2;
		if (id == 1 && !map)
			check_textures(file->content, par);
		if ((id == 2 || id == 3) && !map)
			check_colours(file->content, par, id % 2);
		if (id == 4)
		{
			if (map == 2)
				return (free_params(par), \
printf("Error\nInvalid input file1\n"), exit(1), 0);
			map = 1;
		}
		if (id == -1 || (id && id <= 3 && map))
			return (free_params(par), \
printf("Error\nInvalid input file2\n"), exit(1), 0);
		file = file->next;
	}
	return (1);
}

t_params	*parse_file(int fd)
{
	t_list		*file;
	t_params	*par;

	file = read_file(fd);
	if (!file)
		return (printf("Error\nInvalid input file3\n"), close(fd), \
exit(1), NULL);
	par = ft_calloc(1, sizeof(t_params));
	par->maplist = file;
	par->fd = fd;
	par->ceil = -1;
	par->floor = -1;
	check_formatting(file, par);
	if (!par->colours || !par->textures)
		return (printf("Error\nInvalid input file4\n"), close(fd), \
exit(1), NULL);
	par->map = map_create(file);
	map_check(par);
	return (par);
}
