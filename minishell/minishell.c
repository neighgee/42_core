/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shivani <shivani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 14:18:15 by mwin              #+#    #+#             */
/*   Updated: 2026/02/14 22:50:43 by shivani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

volatile sig_atomic_t	g_sigint = 0;

int	check_sigint(char **s, int *exit_code)
{
	if (!g_sigint)
		return (0);
	*exit_code = 130;
	g_sigint = 0;
	if (*s && (*s)[0] == '\0')
		return (free(*s),*s = NULL, 1);
	return (0);
}

int	actual_loop(char ***dupenvp)
{
	char	*input_string;
	int		can_ex;
	int		exit_code;

	exit_code = 0;
	can_ex = 0;
	while (1)
	{
		input_string = readline("minishell> ");
		if (ctrl_d(input_string))
		{
			write(1, "exit\n", 5);
			break ;
		}
		if (check_sigint(&input_string, &exit_code))
			continue ;
		can_ex = 0;
		check_input(&input_string, dupenvp, &exit_code, &can_ex);
		if (can_ex)
			break ;
	}
	return (exit_code);
}

int	main(int argc, char **argv, char **envp)
{
	char	***dupenvp;
	int		exit_code;

	(void)argc;
	(void)argv;
	dupenvp = dup_envp(envp);
	if (!dupenvp)
		return (1);
	initialise_signals();
	exit_code = actual_loop(dupenvp);
	rl_clear_history();
	if (*dupenvp)
		free_arr(*dupenvp);
	if (dupenvp)
		free(dupenvp);
	return (exit_code);
}
