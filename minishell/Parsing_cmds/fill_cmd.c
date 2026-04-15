/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 20:05:24 by mwin              #+#    #+#             */
/*   Updated: 2026/02/17 20:25:10 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	skip_spc(t_fillc *fc)
{
	while (*(fc->ptr) == ' ')
		fc->ptr++;
}

int	copy_one_token(t_fillc *fc, char **cmds)
{
	if (fc->heredoc_next)
	{
		cmds[fc->i] = copy_hd_target(&(fc->ptr), fc->envp,
				fc->exit_code, &(fc->quoted));
		fc->heredoc_next = 0;
	}
	else
		cmds[fc->i] = copy_cmds_expand(&(fc->ptr),
				fc->envp, fc->exit_code, &(fc->quoted));
	if (!cmds[fc->i])
		return (-1);
	return (0);
}

void	eat_tok(t_fillc *fc, char **cmds)
{
	if (is_hd(cmds[fc->i]))
		fc->heredoc_next = 1;
	fc->i++;
}

void	drop_tok(t_fillc *fc, char **cmds)
{
	free(cmds[fc->i]);
	cmds[fc->i] = NULL;
}
