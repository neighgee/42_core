/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_cmds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 20:41:00 by smariapp          #+#    #+#             */
/*   Updated: 2026/02/10 21:37:28 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	dw_builtin(char **args, char ***envp)
{
	if (ft_strncmp(args[0], "cd", 3) == 0)
		return (cd(envp, args));
	if (ft_strncmp(args[0], "echo", 5) == 0)
		return (echo(args));
	if (ft_strncmp(args[0], "env", 4) == 0)
		return (env(*envp));
	if (ft_strncmp(args[0], "export", 6) == 0)
		return (export(envp, args, 1));
	if (ft_strncmp(args[0], "unset", 6) == 0)
		return (unset(envp, args));
	if (ft_strncmp(args[0], "pwd", 4) == 0)
		return (pwd(*envp));
	return (-1);
}
