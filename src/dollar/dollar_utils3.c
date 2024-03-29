/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperrin <sperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 15:21:58 by sperrin           #+#    #+#             */
/*   Updated: 2021/03/08 17:08:24 by sperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_key(char *arg, t_list *envp)
{
	char	*variable;
	t_list	*tmp_list;

	if (!(variable = ft_strdup("")))
		exit_err_msg(MALLOC_ERR);
	tmp_list = envp;
	while (tmp_list && tmp_list->next)
	{
		if (ft_strnequal((char*)tmp_list->content, arg, ft_strlen(arg)))
			variable = ft_strnjoin_free(variable,
			(char*)tmp_list->content, ft_strlen((char*)tmp_list->content));
		tmp_list = tmp_list->next;
	}
	if (ft_strequal(variable, ""))
	{
		SAFE_FREE(variable);
		return (NULL);
	}
	return (variable);
}

char	*take_dollar(char *line, int *i)
{
	char	*tmp;
	int		*a;

	tmp = NULL;
	tmp = ft_strnjoin_free(tmp, &line[*i], 1);
	(*i)++;
	a = i;
	tmp = take_dollar_bis(line, i, tmp);
	if (a != i)
		return (tmp);
	if (ft_isdigit(line[*i]))
	{
		tmp = ft_strnjoin_free(tmp, &line[*i], 1);
		(*i)++;
		return (tmp);
	}
	while (line[*i] != '\'' && line[*i] != '\"' && line[*i] != '\0'
			&& line[*i] != '$' && line[*i] != '/' && line[*i] != '\\'
			&& line[*i] != '=' && (ft_isalnum(line[*i]) || line[*i] == '_'))
	{
		tmp = ft_strnjoin_free(tmp, &line[*i], 1);
		(*i)++;
	}
	return (tmp);
}

char	*take_single_quote(char *line, int *i)
{
	char	*tmp;
	int		a;
	int		b;

	tmp = NULL;
	b = 0;
	tmp = ft_strnjoin_free(tmp, &line[*i], 1);
	(*i)++;
	if (line[*i] == '\"' && line[*i + 1] == '\0')
		return (tmp);
	a = (*i);
	b = check_quote(a, line);
	if (b != 0)
	{
		while (line[*i] != '\'')
		{
			tmp = ft_strnjoin_free(tmp, &line[*i], 1);
			(*i)++;
		}
		tmp = ft_strnjoin_free(tmp, &line[*i], 1);
		(*i)++;
		return (tmp);
	}
	return (tmp);
}

char	*take_ascii(char *line, int *i)
{
	char	*tmp;

	tmp = NULL;
	if (line[*i] == '/')
	{
		tmp = ft_strnjoin_free(tmp, &line[*i], 1);
		(*i)++;
		return (tmp);
	}
	while (line[*i] != '\"' && line[*i] != '\''
		&& line[*i] != '$' && line[*i] != '\0'
		&& line[*i] != '\\')
	{
		tmp = ft_strnjoin_free(tmp, &line[*i], 1);
		(*i)++;
	}
	return (tmp);
}

char	*take_double_quote(char *line, int *i)
{
	char	*tmp;

	tmp = NULL;
	tmp = ft_strnjoin_free(tmp, &line[*i], 1);
	(*i)++;
	while (line[*i] && line[*i] != '\"')
	{
		if (line[*i] == '\\' && line[*i + 1] != '\0')
		{
			tmp = ft_strnjoin_free(tmp, &line[*i], 2);
			(*i) += 2;
		}
		else
		{
			tmp = ft_strnjoin_free(tmp, &line[*i], 1);
			(*i)++;
		}
	}
	if (line[*i] != '\0')
	{
		tmp = ft_strnjoin_free(tmp, &line[*i], 1);
		(*i)++;
	}
	return (tmp);
}
