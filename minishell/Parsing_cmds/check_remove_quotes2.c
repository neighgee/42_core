/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_remove_quotes2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 12:14:01 by mwin              #+#    #+#             */
/*   Updated: 2026/02/17 19:43:09 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_cmds(const char *string, int *quoted)
{
	int		count;

	count = 0;
	while (*string)
	{
		while (*string == ' ')
			string++;
		if (!*string)
			break ;
		count++;
		string = skip_quotes(string, quoted);
	}
	return (count);
}

char	*copy_and_remove_quotes(char ***envp,
	const char *start, const char *end, int *exit_code)
{
	t_quote_tokenizer	t;

	t.envp = envp;
	t.s = start;
	t.end = end;
	t.sq = 0;
	t.dq = 0;
	t.expand = 1;
	t.exit_code = exit_code;
	t.result = ft_strdup("");
	if (!t.result)
		return (NULL);
	while (t.s < t.end && *(t.s))
	{
		if (handle_quotes_and_others(&t))
			continue ;
		t.s++;
	}
	return (t.result);
}

char	*copy_and_remove_quotes_noexp(char ***envp,
	const char *start, const char *end, int *exit_code)
{
	t_quote_tokenizer	t;

	t.envp = envp;
	t.s = start;
	t.end = end;
	t.sq = 0;
	t.dq = 0;
	t.expand = 0;
	t.exit_code = exit_code;
	t.result = ft_strdup("");
	if (!t.result)
		return (NULL);
	while (t.s < t.end && *(t.s))
	{
		if (handle_quotes_and_others(&t))
			continue ;
		t.s++;
	}
	return (t.result);
}

char	*hd_quoted(char *s, int quoted)
{
	if (!s)
		return (NULL);
	if (quoted)
		s = append_char(s, '\1');
	return (s);
}

int	empty_tok(char *s)
{
	if (!s)
		return (1);
	if (s[0] == '\0')
		return (1);
	if (s[0] == '\1' && s[1] == '\0')
		return (1);
	return (0);
}
