/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 11:30:10 by mwin              #+#    #+#             */
/*   Updated: 2025/08/04 15:12:16 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_buffer_append_to_stash(int fd, char *stash)
{
	char	*buffer;
	ssize_t	bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(stash, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		stash = ft_strjoin_free(stash, buffer);
	}
	free(buffer);
	return (stash);
}

size_t	find_include_nl(char *stash)
{
	size_t	len;

	len = 0;
	if (!stash || (stash)[0] == '\0')
		return (0);
	while ((stash)[len] && (stash)[len] != '\n')
		len++;
	if ((stash)[len] == '\n')
		len++;
	return (len);
}

static char	*remove_till_nl(char *stash, size_t n)
{
	char	*new_stash;
	size_t	i;

	if (!stash)
		return (NULL);
	if (n >= ft_strlen(stash))
	{
		free(stash);
		return (NULL);
	}
	new_stash = malloc(sizeof(char) * (ft_strlen(stash) - n + 1));
	if (!new_stash)
	{
		free(stash);
		return (NULL);
	}
	i = 0;
	while ((stash)[n])
		new_stash[i++] = (stash)[n++];
	new_stash[i] = '\0';
	free(stash);
	return (new_stash);
}

static char	*extract_nl_update_stash(char **stash)
{
	size_t	n;
	char	*string;

	if (!*stash || (*stash)[0] == '\0')
		return (NULL);
	n = find_include_nl(*stash);
	string = malloc(sizeof(char) * (n + 1));
	if (!string)
		return (NULL);
	ft_memmove(string, *stash, n);
	string[n] = '\0';
	if ((*stash)[n] == '\0')
	{
		free(*stash);
		*stash = NULL;
		return (string);
	}
	*stash = remove_till_nl(*stash, n);
	if (!*stash)
	{
		free(string);
		return (NULL);
	}
	return (string);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*string;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_buffer_append_to_stash(fd, stash);
	if (!stash)
		return (NULL);
	string = extract_nl_update_stash(&stash);
	if (!string || string[0] == '\0')
	{
		free(string);
		if (stash)
		{
			free(stash);
			stash = NULL;
		}
		return (NULL);
	}
	return (string);
}
