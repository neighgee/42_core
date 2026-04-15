/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 18:11:45 by smariapp          #+#    #+#             */
/*   Updated: 2026/02/16 15:12:24 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	write_error_export(char *var, int fd)
{
	write(fd, "minishell: export: `", 20);
	write(fd, var, ft_strlen(var));
	write(fd, "': not a valid identifier", 25);
	write(fd, "\n", 1);
}

int	check_valid(char *var, int fd)
{
	int	i;

	i = 0;
	if (ft_isalpha(var[i]) || var[i] == '_')
		i++;
	else
		return (write_error_export(var, fd), 1);
	while (var[i])
	{
		if (var[i] == '=')
			return (0);
		else if (ft_isalnum(var[i]) || var[i] == '_')
			i++;
		else
			return (write_error_export(var, fd), 1);
	}
	return (-1);
}

int	export_var_in_env(char ***envp, char *new, char *var)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(var);
	while ((*envp)[i])
	{
		if (ft_strncmp((*envp)[i], var, len) == 0 &&
			(*envp)[i][len] == '=')
		{
			free((*envp)[i]);
			(*envp)[i] = ft_strdup(new);
			return (1);
		}
		i++;
	}
	return (2);
}

int	export_var_add(char ***envp, char *new)
{
	char	**new_envp;
	char	**old_envp;
	int		i;

	i = 0;
	old_envp = *envp;
	while (old_envp[i])
		i++;
	new_envp = malloc(sizeof(char *) * (i + 2));
	if (!new_envp)
		return (0);
	i = 0;
	while (old_envp[i])
	{
		new_envp[i] = ft_strdup(old_envp[i]);
		if (!new_envp[i])
			return (free_arr(new_envp), 0);
		i++;
	}
	new_envp[i++] = ft_strdup(new);
	new_envp[i] = NULL;
	*envp = new_envp;
	free_arr(old_envp);
	return (1);
}
