/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:53:05 by mwin              #+#    #+#             */
/*   Updated: 2026/02/17 15:36:18 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

const char	*skip_quotes(const char *s, int *quoted)
{
	int	sq;
	int	dq;

	sq = 0;
	dq = 0;
	*quoted = 0;
	while (*s)
	{
		if (!dq && *s == '\'')
		{
			sq = !sq;
			*quoted = 1;
		}
		else if (!sq && *s == '"')
		{
			dq = !dq;
			*quoted = 1;
		}
		else if (!sq && !dq && *s == ' ')
			break ;
		s++;
	}
	return (s);
}

char	*append_char(char *result, char c)
{
	char	*temp;

	temp = ft_strjoin_char(result, c);
	free(result);
	return (temp);
}

int	empty_str(char *s)
{
	return (!s || s[0] == '\0');
}

static int	pipe_redrc_sym(t_quote_tokenizer *s, int c)
{
	if (!(s->sq || s->dq))
		return (0);
	if (c == '|')
	{
		s->result = append_char(s->result, '|');
		return (1);
	}
	if (c == '<')
	{
		s->result = append_char(s->result, '\3');
		return (1);
	}
	if (c == '>')
	{
		s->result = append_char(s->result, '\4');
		return (1);
	}
	return (0);
}

int	handle_quotes_and_others(t_quote_tokenizer *s)
{
	int	i;
	int	c;

	c = *(s->s);
	if (!s->dq && c == '\'')
	{
		s->sq = !s->sq;
		return (0);
	}
	if (!s->sq && c == '"')
	{
		s->dq = !s->dq;
		return (0);
	}
	if (s->expand && !s->sq && c == '$')
	{
		if (*(s->s + 1) == '?' && s->exit_code)
			return (append_exit_code(s));
		i = 0;
		if (edge_case_expansion(s->s, &(s->result), *(s->envp), &i))
			return (s->s += i, 1);
	}
	if (pipe_redrc_sym(s, c))
		return (0);
	return (s->result = append_char(s->result, c), 0);
}
