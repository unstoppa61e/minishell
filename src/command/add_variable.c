/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_variable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperrin <sperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 10:14:27 by sperrin           #+#    #+#             */
/*   Updated: 2021/03/04 10:15:15 by sperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void				add_variable(char *argv, t_list *envp)
{
	t_list	*new;
	t_list	*tmp;

	new = malloc(sizeof(t_list));
	if (!new)
		exit_err_msg(MALLOC_ERR);
	new->content = ft_strdup(argv);
	while (envp && envp->next && envp->next->next)
		envp = envp->next;
	tmp = envp->next;
	envp->next = new;
	new->next = tmp;
}
