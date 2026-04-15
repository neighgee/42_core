/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 20:40:46 by smariapp          #+#    #+#             */
/*   Updated: 2026/02/16 17:01:30 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	write_cd_error(int fd, char *path, int home)
{
	if (home)
	{
		write(fd, "minishell: cd: HOME not set\n", 28);
		return ;
	}
	write(fd, "minishell: cd: ", 16);
	write(fd, path, ft_strlen(path));
	write(fd, ": No such file or directory\n", 28);
}

char	*dw_del_dir(char **envp, char *path)
{
	char	*newpwd;
	char	*tmp;

	newpwd = getcwd(NULL, 0);
	if (newpwd)
		return (newpwd);
	write(2, "cd: error retrieving current directory: ", 40);
	write(2, "getcwd: cannot access parent directories: ", 42);
	write(2, "No such file or directory\n", 26);
	newpwd = ft_strjoin(ft_getenv_custom(envp, "PWD"), "/");
	tmp = ft_strjoin(newpwd, path);
	return (free(newpwd), tmp);
}

char	*generate_old_pwd(void)
{
	char	*path;
	char	*ret;

	path = getcwd(NULL, 0);
	ret = ft_strjoin("OLDPWD=", path);
	free(path);
	return (ret);
}

char	*cd_2(char ***envp, char *path)
{
	int		i;
	char	*oldpwd;
	char	*newpwd;

	i = 0;
	oldpwd = generate_old_pwd();
	if (access(path, F_OK | X_OK) != 0 || chdir(path) == -1)
		return (free(oldpwd), write_cd_error(2, path, 0), NULL);
	while ((*envp)[i])
	{
		if (!ft_strncmp((*envp)[i], "PWD=", 4))
		{
			oldpwd = free_old_ret_newpwd(oldpwd, (*envp)[i]);
			newpwd = dw_del_dir(*envp, path);
			free((*envp)[i]);
			(*envp)[i] = ft_strjoin("PWD=", newpwd);
			free(newpwd);
			break ;
		}
		i++;
	}
	return (oldpwd);
}

int	cd(char ***envp, char **argv)
{
	char	*oldpwd;
	char	*path;
	char	*home;

	if (!argv[1] || !*(argv[1]))
	{
		home = ft_getenv_custom(*envp, "HOME");
		if (!home || *home == '\0')
			return (write_cd_error(2, NULL, 1), 1);
		path = home;
	}
	else if (argv[2])
		return (write(2, "minishell: cd: too many arguments\n", 34), 1);
	else
		path = argv[1];
	oldpwd = cd_2(envp, path);
	if (!oldpwd || !*oldpwd)
		return (free(oldpwd), 1);
	return (indiv_export(envp, oldpwd), free(oldpwd), 0);
}
