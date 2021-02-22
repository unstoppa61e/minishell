/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_error_invalid_identifier.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 17:41:09 by sperrin           #+#    #+#             */
/*   Updated: 2021/02/18 16:03:06 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	put_error_invalid_identifier(const char *command, const char *arg)
{
	ft_putstr("bash: ");
	ft_putstr(command);
	ft_putstr(": `");
	ft_putstr(arg);
	ft_putendl("': not a valid identifier");
}