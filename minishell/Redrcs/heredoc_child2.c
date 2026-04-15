/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_child2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 15:26:18 by mwin              #+#    #+#             */
/*   Updated: 2026/02/17 15:26:26 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	hd_freeline(char *input, char *line)
{
	if (line != input)
		free(line);
	free(input);
}

int	hd_loop(t_hered *heredoc, int fd, char ***envp, int status)
{
	char	*input;
	char	*line;
	size_t	sym_len;

	sym_len = ft_strlen(heredoc->symbol);
	while (1)
	{
		input = readline("heredoc> ");
		if (hd_delim(input, heredoc->symbol, sym_len))
			break ;
		line = input;
		if (heredoc->expand)
		{
			line = hd_expand(input, envp, status);
			if (!line)
				return (free(input), 1);
		}
		hd_write(fd, line);
		hd_freeline (input, line);
	}
	free(input);
	if (g_sigint)
		return (130);
	return (0);
}
