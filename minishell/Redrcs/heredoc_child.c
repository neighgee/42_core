/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_child.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 12:10:49 by mwin              #+#    #+#             */
/*   Updated: 2026/02/17 15:23:14 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	quoted(const char *delim)
{
	int	i;

	i = 0;
	while (delim && delim[i])
	{
		if (delim[i] == '\'' || delim[i] == '"')
			return (1);
		i++;
	}
	return (0);
}

int	hd_delim(char *input, char *symbol, size_t sym_len)
{
	if (!input)
		return (1);
	if (g_sigint)
		return (1);
	if (!ft_strncmp(input, symbol, sym_len + 1))
		return (1);
	return (0);
}

void	hd_write(int fd, char *input)
{
	write(fd, input, ft_strlen(input));
	write(fd, "\n", 1);
}

int	handle_dollar(t_quote_tokenizer *t)
{
	int	i;

	if (*(t->s + 1) == '?' && t->exit_code)
		return (append_exit_code(t));
	i = 0;
	if (edge_case_expansion(t->s, &(t->result), *(t->envp), &i))
	{
		t->s = t->s + i;
		return (1);
	}
	return (0);
}

char	*hd_expand(const char *src, char ***envp, int status)
{
	t_quote_tokenizer	t;

	t.envp = envp;
	t.s = src;
	t.end = NULL;
	t.sq = 0;
	t.dq = 0;
	t.expand = 1;
	t.exit_code = &status;
	t.result = ft_strdup("");
	if (!t.result)
		return (NULL);
	while (*(t.s))
	{
		if (*(t.s) == '$')
		{
			if (handle_dollar(&t))
				continue ;
		}
		t.result = append_char(t.result, *(t.s));
		if (!t.result)
			return (NULL);
		t.s++;
	}
	return (t.result);
}
