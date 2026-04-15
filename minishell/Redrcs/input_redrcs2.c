/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_redrcs2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 21:11:12 by smariapp          #+#    #+#             */
/*   Updated: 2026/02/17 14:37:55 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_redir(char c)
{
	return (c == '<' || c == '>');
}

// static char	*rm_quotes_token(const char *s)
// {
// 	int	len;

// 	if (!s)
// 		return (NULL);
// 	len = (int)ft_strlen(s);
// 	if (len >= 2 && ((s[0] == '\'' && s[len -1] == '\'')
// 			|| (s[0] == '"' && s[len - 1] == '"')))
// 		return (substr_len(s, 1, len - 2));
// 	return (ft_strdup(s));
// }

int	quotedornot(const char *s)
{
	int	len;

	if (!s)
		return (0);
	len = (int)ft_strlen(s);
	if (len > 0 && s[len - 1] == '\1')
		return (1);
	return (0);
}

char	*remv_c1(const char *s)
{
	int		len;
	int		i;
	char	*dup;

	if (!s)
		return (NULL);
	len = (int)ft_strlen(s);
	if (len > 0 && s[len - 1] == '\1')
		len--;
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[len] = '\0';
	return (dup);
}

static t_hered	*new_hd(char *token)
{
	t_hered	*heredoc;

	heredoc = malloc(sizeof(t_hered));
	if (!heredoc)
		return (NULL);
	ft_bzero(heredoc, sizeof(t_hered));
	heredoc->expand = 1;
	if (quotedornot(token))
		heredoc->expand = 0;
	heredoc->symbol = remv_c1(token);
	if (!heredoc->symbol)
		return (free(heredoc), NULL);
	heredoc->temp_path = NULL;
	heredoc->next = NULL;
	return (heredoc);
}

int	append_hd(t_command *cmd, char *token)
{
	t_hered	*node;
	t_hered	*last;

	node = new_hd(token);
	if (!node)
		return (-1);
	if (!cmd->heredocs)
	{
		cmd->heredocs = node;
		return (0);
	}
	last = cmd->heredocs;
	while (last->next)
		last = last->next;
	last->next = node;
	return (0);
}
