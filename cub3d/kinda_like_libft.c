/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kinda_like_libft.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 17:54:34 by smariapp          #+#    #+#             */
/*   Updated: 2026/04/06 21:03:03 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_file_type(char *file, char *type)
{
	int	len;
	int	nl;

	len = ft_strlen(file);
	nl = 0;
	if (file[len - 1] == '\n')
		nl = 1;
	file += (len - ft_strlen(type) - nl);
	if (ft_strncmp(file, type, ft_strlen(type)) != 0)
		return (0);
	return (1);
}

int	ft_arrlen(char **arr)
{
	int	count;

	count = 0;
	while (arr[count])
		count++;
	return (count);
}

int	gimme_fd(char *file)
{
	int		fd;
	int		len;
	char	*f;
	int		i;

	if (!file)
		return (-1);
	len = ft_strlen(file);
	i = 0;
	if (file[len - 1] == '\n')
		len -= 1;
	f = malloc((len + 1) * sizeof(char));
	while (i < len)
	{
		f[i] = file[i];
		i++;
	}
	f[len] = '\0';
	fd = open(f, O_RDONLY);
	free(f);
	return (fd);
}
