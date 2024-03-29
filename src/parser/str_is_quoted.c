/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_is_quoted.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 11:36:02 by monoue            #+#    #+#             */
/*   Updated: 2021/02/24 11:09:12 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	str_is_quoted(const char *str)
{
	const size_t	len = ft_strlen(str);
	char			quote;

	if (len < 2 || !is_quote_char(str[0]))
		return (false);
	quote = str[0];
	if (quote == '\'')
		return (str[len - 1] == quote);
	else
		return (str[len - 1] == quote && !is_escaped(str, len - 1));
}

bool	str_is_quoted_by_double(const char *str)
{
	const size_t len = ft_strlen(str);

	if (len < 2)
		return (false);
	return (str[0] == '"' && str[0] == str[len - 1]
												&& !is_escaped(str, len - 1));
}
