/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 20:41:10 by smariapp          #+#    #+#             */
/*   Updated: 2026/02/17 12:36:40 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env(char **envp)
{
	int	a;

	while (*envp)
	{
		if (ft_strchr(*envp, '=') != NULL)
		{
			a = ft_strlen(*envp);
			if (write(1, *envp, a) < a
				|| write(1, "\n", 1) < 1)
				return (write(2, "env: write error: No space \
left on device\n", 42), 1);
		}
		envp++;
	}
	return (0);
}
