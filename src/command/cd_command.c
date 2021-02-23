/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 17:40:49 by sperrin           #+#    #+#             */
/*   Updated: 2021/02/23 13:26:25 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		old_pwd(t_list *envp)
{
	char	*pwd;
	char	*oldpwd;
	char	*buf;
	char	*key;
	int		count;

	buf = NULL;
	pwd = getcwd(buf, PATH_MAX);
	oldpwd = ft_strjoin("OLDPWD=", pwd);
	key = get_key(oldpwd);
	count = ft_strlen(key);
	if (same_key(key, envp) == 1)
	{
		while (envp && envp->next)
		{
			if (ft_strncmp((char*)envp->content, key, count) == 0)
			{
				SAFE_FREE(envp->content);
				envp->content = ft_strdup(oldpwd);
			}
			envp = envp->next;
		}
	}
	else
		add_variable(oldpwd, envp);
	SAFE_FREE(key);
	SAFE_FREE(oldpwd);
	SAFE_FREE(pwd);
}

void		new_pwd(t_list *envp)
{
	char	*pwd;
	char	*new_pwd;
	char	*buf;
	char	*key;
	char	*arg;
	int		count;

	buf = NULL;
	pwd = getcwd(buf, PATH_MAX);
	new_pwd = ft_strjoin("PWD=", pwd);
	while (envp && envp->next)
	{
		if (ft_strncmp((char*)envp->content, "PWD=", 4) == 0)
		{
			SAFE_FREE(envp->content);
			envp->content = ft_strdup(new_pwd);
		}
		envp = envp->next;
	}
	SAFE_FREE(new_pwd);
	SAFE_FREE(pwd);
}

void		put_error(char *argv)
{
	ft_putstr_fd("bash: cd: ", 1);
	ft_putstr_fd(argv, 1);
	ft_putstr_fd(": ", 1);
	ft_putstr_fd(strerror(errno), 1);
	ft_putstr_fd("\n", 1);
}

void		cd(char **argv, t_list *envp)
{
	char	*variable;
	int		count;

	variable = NULL;
	if (find_key("HOME=", envp) == NULL)
	{
		g_last_exit_status = EXIT_FAILURE;
		return (ft_putstr_fd("bash: cd: HOME not set\n", 1));
	}
	old_pwd(envp);
	if ((argv[1] == NULL) || (ft_strcmp(argv[1], "~") == 0))
	{
		while (envp && envp->next)
		{
			if (ft_strncmp((char*)envp->content, "HOME=", ft_strlen("HOME=")) == 0)
				variable = ft_strdup((char*)envp->content);
			envp = envp->next;
		}
		if (variable != NULL)
		{
			count = ft_strrchr_int(variable, '=');
			argv[1] = ft_substr(variable, count + 1,
				ft_strlen(variable) - count);
			SAFE_FREE(variable);
		}
	}
	if (chdir(argv[1]) == ERROR)
	{
		put_error(argv[1]);
		g_last_exit_status = 1;
	}
	new_pwd(envp);
}
