/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:51:35 by mwin              #+#    #+#             */
/*   Updated: 2025/08/09 16:40:01 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_message(char	*error_msg)
{
	ft_printf("Error\n%s\n", error_msg);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	if (i < n)
	{
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return (0);
}

char	*ft_strdup(const char *s)
{
	char	*new_s;
	size_t	s_len;
	size_t	i;

	i = 0;
	s_len = ft_strlen(s);
	new_s = (char *)malloc((s_len + 1) * sizeof(char));
	if (new_s == NULL)
		return (NULL);
	while (i < s_len)
	{
		new_s[i] = s[i];
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}

void	access_fail_exit(char *error_msg, t_game *game)
{
	error_message(error_msg);
	quit_program(game);
	exit(1);
}
