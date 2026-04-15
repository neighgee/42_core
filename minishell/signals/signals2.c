/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 14:32:27 by mwin              #+#    #+#             */
/*   Updated: 2026/02/10 21:05:47 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	heredoc_sigint(int signal)
{
	(void)signal;
	g_sigint = 1;
	write(1, "\n", 1);
	close(STDIN_FILENO);
}
