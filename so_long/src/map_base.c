/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_base.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 15:08:09 by mwin              #+#    #+#             */
/*   Updated: 2025/08/08 14:12:30 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**read_lines(int fd, char **map)
{
	int		len;
	int		i;
	char	*line_rd;

	i = 0;
	line_rd = get_next_line(fd);
	if (!line_rd)
	{
		map[0] = NULL;
		return (map);
	}
	while (line_rd)
	{
		len = ft_strlen(line_rd);
		if (len > 0 && line_rd[len - 1] == '\n')
			line_rd[len - 1] = '\0';
		map[i] = line_rd;
		i++;
		line_rd = get_next_line(fd);
	}
	map[i] = NULL;
	return (map);
}

static char	**read_file_duplicate(int n, const char *file)
{
	char	**map;
	int		fd;

	map = malloc(sizeof(char *) * (n + 1));
	if (!map)
		return (error_message("Malloc failed"), NULL);
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		error_message("File cannot opened -read_file_duplicate");
		free(map);
		return (NULL);
	}
	map = read_lines(fd, map);
	close(fd);
	return (map);
}

char	**check_map(const char *file)
{
	char	**map;
	int		fd;
	char	*line_rd;
	int		n;

	n = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (error_message("File cannot be opened - check_map"), NULL);
	line_rd = get_next_line(fd);
	while (line_rd)
	{
		free(line_rd);
		n++;
		line_rd = get_next_line(fd);
	}
	close (fd);
	if (n == 0)
		return (error_message("Empty map"), NULL);
	map = read_file_duplicate(n, file);
	if (!map)
		return (NULL);
	return (map);
}
