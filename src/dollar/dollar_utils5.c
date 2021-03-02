/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_utils5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 13:43:56 by sperrin           #+#    #+#             */
/*   Updated: 2021/03/02 09:07:00 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*take_dollar_bis(char *line, size_t *index, char *tmp)
{
	if (line[*index] == '$')
	{
		SAFE_FREE(tmp);
		(*index)++;
		return (tmp = ft_strdup("(process ID)"));
	}
	if (line[*index] == '?')
	{
		tmp = ft_strnjoin_free(tmp, &line[*index], 1);
		(*index)++;
		return (tmp);
	}
	return (tmp);
}
