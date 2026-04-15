/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 21:05:44 by mwin              #+#    #+#             */
/*   Updated: 2026/02/17 12:12:57 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Function appends the exit code
1. changes the exit code from number to char
2. skips the $? so that it does not print out
3. returns the appended result (aka echo $? will be echo (exit no.)) */
int	append_exit_code(t_quote_tokenizer *s)
{
	char	*exit_c;
	char	*temp;

	exit_c = ft_itoa(*(s->exit_code));
	if (!exit_c)
		return (0);
	temp = ft_strjoin(s->result, exit_c);
	free(s->result);
	free(exit_c);
	if (!temp)
		return (0);
	s->result = temp;
	s->s += 2;
	return (1);
}

/* First character needs to be an alphabet or _
If true, return string length (aka number of characters)
If not, return 0 (aka string don't exist) */
static int	extract_var_name(const char *string)
{
	int	i;

	i = 0;
	if (!ft_isalpha(string[i]) && string[i] != '_')
		return (0);
	while (ft_isalnum(string[i]) || string[i] == '_')
		i++;
	return (i);
}

/*
Function uses strncmp to find the data, eg. find $HOME= in envp data
1. If found, it returns address of the the start of the envp variable
,aka after '='
2. If not found, it returns an empty string for strjoin to append */
static char	*find_var_from_envp(char *var, char **envp)
{
	int	i;
	int	len;

	if (!var || !envp)
		return (ft_strdup(""));
	i = 0;
	len = ft_strlen(var);
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], var, len) && envp[i][len] == '=')
			return (ft_strdup(envp[i] + len + 1));
		i++;
	}
	return (ft_strdup(""));
}

/*
Function finds the length of the variable with extract_var_name
If string does not exist, it returns empty string
If string exists,
1. it finds the address of the variable string
2. appends the variable to the result string
3. returns the joined string */
static char	*append_actual_values(int *i, const char *cmd, char *result,
	char **envp)
{
	char	*var;
	char	*env_value;
	char	*updated_result;
	int		var_len;

	var_len = extract_var_name(cmd + *i + 1);
	if (var_len == 0)
	{
		updated_result = ft_strjoin_char(result, '$');
		free(result);
		(*i)++;
		return (updated_result);
	}
	var = ft_substr(cmd, *i + 1, var_len);
	env_value = find_var_from_envp(var, envp);
	if (env_value && env_value[0] == '\0' && redrc_last(result))
	{
		free(env_value);
		env_value = ft_strdup("\1");
	}
	updated_result = ft_strjoin(result, env_value);
	free(result);
	free(var);
	*i += var_len + 1;
	return (free(env_value), updated_result);
}

int	edge_case_expansion(const char *cmd, char **result, char **envp, int *i)
{
	if (cmd[*i] == '$')
		*result = append_actual_values(i, cmd, *result, envp);
	else
		return (0);
	return (1);
}
