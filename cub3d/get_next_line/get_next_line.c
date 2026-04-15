/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:29:52 by smariapp          #+#    #+#             */
/*   Updated: 2025/08/29 15:47:39 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_alloc(char *line, char *buf, int ix)
{
	char	*new_line;
	size_t	len;

	len = ft_strlen(line);
	new_line = malloc(len + ix + 1);
	if (!new_line)
		return (NULL);
	if (line)
	{
		ft_strcopy(line, new_line, len);
		free(line);
	}
	ft_strcopy(buf, &new_line[len], ix);
	return (new_line);
}

char	*ft_body(int fd, char **rem, char *buf, char *line)
{
	int		ix;
	ssize_t	n;

	n = read(fd, buf, BUFFER_SIZE);
	while (n > 0)
	{
		buf[n] = '\0';
		ix = ft_strchrm(buf, '\n');
		if (ix >= 0)
		{
			free(*rem);
			line = ft_alloc(line, buf, ix + 1);
			*rem = ft_allocate_rem(&buf[ix + 1]);
			break ;
		}
		line = ft_alloc(line, buf, n);
		n = read(fd, buf, BUFFER_SIZE);
	}
	if (n <= 0)
		free(*rem);
	if (n <= 0)
		*rem = NULL;
	return (line);
}

char	*get_next_line(int fd, int flag)
{
	char		*str;
	static char	*rem;
	char		*new_rem;
	char		*buf;
	int			ix;

	if (flag && rem)
		return (free(rem), NULL);
	if (flag || fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	ix = ft_strchrm(rem, '\n');
	if (ix >= 0)
	{
		str = ft_alloc(NULL, rem, ix + 1);
		new_rem = ft_allocate_rem(&rem[ix + 1]);
		free(rem);
		rem = new_rem;
		return (free(buf), str);
	}
	str = ft_body(fd, &rem, buf, ft_allocate_rem(rem));
	return (free(buf), str);
}
