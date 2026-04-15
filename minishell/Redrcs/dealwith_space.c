/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealwith_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 21:20:50 by mwin              #+#    #+#             */
/*   Updated: 2026/02/14 10:52:31 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	inside_q(char c, int *sq, int *dq)
{
	if (!*dq && c == '\'')
		*sq = !*sq;
	else if (!*sq && c == '"')
		*dq = !*dq;
}

void	loop_copy(const char *s, size_t *i, size_t *j, char *out)
{
	int	sq;
	int	dq;
	int	fd_stuck;

	sq = 0;
	dq = 0;
	while (s[*i])
	{
		inside_q(s[*i], &sq, &dq);
		if (!sq && !dq && is_redir(s[*i]))
		{
			fd_stuck = (*i > 0 && ft_isdigit(s[*i - 1]) && s[*i - 1] != ' ');
			if (*j && out[*j - 1] != ' ')
				out[(*j)++] = ' ';
			if (fd_stuck)
				out[(*j)++] = '\2';
			out[(*j)++] = s[(*i)++];
			if (s[*i] && s[*i - 1] == s[*i])
				out[(*j)++] = s[(*i)++];
			if (s[*i] && s[*i] != ' ')
				out[(*j)++] = ' ';
		}
		else
			out[(*j)++] = s[(*i)++];
	}
}

char	*add_spc_redrc(const char *s)
{
	size_t	i;
	size_t	j;
	char	*out;

	if (!s)
		return (NULL);
	out = malloc(ft_strlen(s) * 3 + 1);
	if (!out)
		return (NULL);
	i = 0;
	j = 0;
	loop_copy(s, &i, &j, out);
	out[j] = '\0';
	return (out);
}
