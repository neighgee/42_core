/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redrc_syn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 10:59:53 by mwin              #+#    #+#             */
/*   Updated: 2026/02/16 12:43:16 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	bad_symbol(int *checker, char *token)
{
	*checker = -2;
	if (token && token[0] == '\2' && token[1])
		unexpected_msg(token[1]);
	else if (token)
		unexpected_msg(token[0]);
	else
		unexpected_msg('\n');
}

static int	count_args(char **args)
{
	int	i;

	i = 0;
	while (args && args[i])
		i++;
	return (i);
}

int	parse_redir_symbol_fd(char **args, int *checker, int *i, int *fd)
{
	*fd = -1;
	if (str_is_num(args[*i]) && args[*i + 1] && args[*i + 1][0] == '\2'
		&& is_redir(args[*i + 1][1]))
		*fd = ft_atoi(args[(*i)++]);
	return (check_append_heredoc(args[*i], checker));
}

/* Function builds a new argv without redirection symbols or targets
1. Check_redirects stores the right info into the linkedlist cmd
2. Only real argv stays in cmd->arguments */
int	store_symbols(t_command *cmd, int *exit_code)
{
	char	**old;
	char	**new;

	if (!cmd || !cmd->arguments)
		return (1);
	cmd->infd_new = 0;
	cmd->outfd_new = 1;
	old = cmd->arguments;
	new = malloc(sizeof(char *) * (count_args(old) + 1));
	if (!new)
		return (0);
	ft_bzero(new, sizeof(char *) * (count_args(old) + 1));
	if (!skip_redrcs(cmd, old, new, exit_code))
		return (free_arr(new), 0);
	free_arr(cmd->arguments);
	cmd->arguments = new;
	return (1);
}

int	close_fds(int status, int dummy_in, int dummy_out, int dummy_err)
{
	if (dummy_in > 2)
		close(dummy_in);
	if (dummy_out > 2)
		close(dummy_out);
	if (dummy_err > 2)
		close(dummy_err);
	if (status == -130 || status == -1 || status == -2)
		return (-status);
	return (0);
}
