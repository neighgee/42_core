/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 20:33:40 by smariapp          #+#    #+#             */
/*   Updated: 2026/02/17 10:30:19 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_getenv_custom(char **envp, char *var_name)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(var_name);
	while (envp[i])
	{
		if (ft_strncmp(envp[i], var_name, len) == 0 && envp[i][len] == '=')
		{
			return (&envp[i][len + 1]);
		}
		i++;
	}
	return (NULL);
}

char	***dup_envp(char **envp)
{
	int		i;
	int		count;
	char	***new_envp;

	i = 0;
	count = 0;
	while (envp && envp[count])
		count++;
	new_envp = malloc(sizeof(char **));
	if (!new_envp)
		return (NULL);
	*new_envp = malloc(sizeof(char *) * (count + 1));
	if (!*new_envp)
		return (free(new_envp), NULL);
	while (i < count)
	{
		(*new_envp)[i] = ft_strdup(envp[i]);
		if (!(*new_envp)[i])
			return ((*new_envp)[i] = NULL, free_arr((*new_envp))
			, free(new_envp), NULL);
		i++;
	}
	(*new_envp)[count] = NULL;
	return (new_envp);
}
