/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperrin <sperrin@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 17:40:49 by sperrin           #+#    #+#             */
/*   Updated: 2021/03/15 22:06:22 by sperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	old_pwd(t_list *envp)
{
	const char	*oldpwd_key = "OLDPWD=";
	char		*pwd;
	char		*oldpwd;

	pwd = find_key("PWD=", envp);
	if (!pwd)
		return ;
	oldpwd = ft_strjoin(oldpwd_key, &pwd[4]);
	if (same_key(oldpwd_key, envp))
	{
		while (envp && envp->next)
		{
			if (ft_strnequal((char*)envp->content, oldpwd_key,
														ft_strlen(oldpwd_key)))
			{
				SAFE_FREE(envp->content);
				envp->content = ft_strdup(oldpwd);
			}
			envp = envp->next;
		}
	}
	else
		add_variable(oldpwd, envp);
	SAFE_FREE(oldpwd);
	SAFE_FREE(pwd);
}

static void	new_pwd(t_list *envp)
{
	const char	*pwd_key = "PWD=";
	char		*pwd;
	char		*new_pwd;
	char		*buf;

	buf = NULL;
	pwd = getcwd(buf, PATH_MAX);
	new_pwd = ft_strjoin(pwd_key, pwd);
	if (same_key(pwd_key, envp))
	{
		while (envp && envp->next)
		{
			if (ft_strnequal((char*)envp->content, pwd_key, ft_strlen(pwd_key)))
			{
				SAFE_FREE(envp->content);
				envp->content = ft_strdup(new_pwd);
			}
			envp = envp->next;
		}
	}
	else
		add_variable(new_pwd, envp);
	SAFE_FREE(new_pwd);
	SAFE_FREE(pwd);
}

static void	put_error(char *argv, char **arg)
{
	ft_putstr_err("bash: cd: ");
	ft_putstr_err(argv);
	ft_putstr_err(": ");
	ft_putendl_err(strerror(errno));
	g_last_exit_status = EXIT_FAILURE;
	ft_free_split(arg);
}

static char	*find_home(t_list *envp)
{
	const char	*home_key = "HOME=";
	char		*variable;
	int			count;
	char		*str;

	str = NULL;
	while (envp && envp->next)
	{
		if (ft_strnequal((char*)envp->content, home_key, ft_strlen(home_key)))
			variable = ft_strdup((char*)envp->content);
		envp = envp->next;
	}
	if (variable != NULL)
	{
		count = ft_strrchr_int(variable, '=');
		str = ft_substr_free(variable, count + 1, ft_strlen(variable) - count);
	}
	if (str_is_of_tabs_or_spaces(str))
		SAFE_FREE(str);
	return (str);
}

void		cd(char **argv, t_list *envp, char *home_key)
{
	char	**arg;

	arg = set_command_argv(argv, envp);
	home_key = find_key("HOME=", envp);
	if (!home_key && argv[1] == NULL)
	{
		error_cd(home_key, arg);
		return ;
	}
	SAFE_FREE(home_key);
	if ((arg[1] == NULL) || (ft_strequal(arg[1], "~")))
	{
		arg[1] = find_home(envp);
		arg[2] = NULL;
	}
	if (!arg[1] || (ft_strequal(arg[1], "") && !g_global))
		;
	else if (chdir(arg[1]) == ERROR)
	{
		put_error(arg[1], arg);
		return ;
	}
	old_pwd(envp);
	new_pwd(envp);
	ft_free_split(arg);
}
