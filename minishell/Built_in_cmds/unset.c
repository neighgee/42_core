/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 16:08:07 by smariapp          #+#    #+#             */
/*   Updated: 2026/02/02 18:58:00 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	this_is_not_it(char *envp_var, char *arg)
{
	int	len;

	len = ft_strlen(arg);
	return (!(ft_strncmp(envp_var, arg, len) == 0
			&& (envp_var[len] == '=' || envp_var[len] == '\0')));
}

int	indiv_unset(char ***envp, char *arg)
{
	int		i;
	int		j;
	int		count;
	char	**new_envp;

	i = 0;
	j = 0;
	count = ft_arrlen(*envp);
	new_envp = malloc(sizeof(char *) * count);
	if (!new_envp)
		return (1);
	while (i < count)
	{
		if (this_is_not_it((*envp)[i], arg))
		{
			new_envp[j] = ft_strdup((*envp)[i]);
			if (!new_envp[j++])
				return (free_arr((new_envp)), 1);
		}
		i++;
	}
	new_envp[count - 1] = NULL;
	free_arr(*envp);
	*envp = new_envp;
	return (0);
}

int	unset(char ***envp, char **args)
{
	int		n;
	int		i;
	char	*var;

	n = ft_arrlen(args);
	i = 1;
	if (n == 1)
		return (0);
	else
	{
		while (args[i])
		{
			var = ft_getenv_custom(*envp, args[i]);
			if (var != NULL)
				n = indiv_unset(envp, args[i]);
			i++;
		}
	}
	return (0);
}
