/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_syn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 17:08:42 by mwin              #+#    #+#             */
/*   Updated: 2026/02/17 19:43:15 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_hd(char *s)
{
	if (!s)
		return (0);
	if (s[0] == '\2' && s[1])
		s++;
	if (!ft_strncmp(s, "<<", 3))
		return (1);
	return (0);
}

char	*copy_hd_target(const char **ptr, char ***envp
	, int *exit_code, int *quoted)
{
	const char	*start;
	const char	*end;
	char		*ret;

	start = *ptr;
	end = skip_quotes(*ptr, quoted);
	*ptr = end;
	ret = copy_and_remove_quotes_noexp(envp, start, end, exit_code);
	if (!ret)
		return (NULL);
	ret = hd_quoted(ret, *quoted);
	return (ret);
}

char	*copy_cmds_expand(const char **string, char ***envp,
	int *exit_code, int *quoted)
{
	const char	*start;
	const char	*end;

	start = *string;
	end = skip_quotes(*string, quoted);
	*string = end;
	return (copy_and_remove_quotes(envp, start, end, exit_code));
}
