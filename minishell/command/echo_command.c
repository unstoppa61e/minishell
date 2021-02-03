/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 17:40:55 by sperrin           #+#    #+#             */
/*   Updated: 2021/02/03 10:15:31 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	echo(char **argv)
{
	size_t	index;

	index = 1;
	if (ft_strequal(argv[index], "-n"))
	{
		index++;
		while (argv[index] != '\0')
		{
			ft_putstr(argv[index++]);
			if (argv[index] != NULL)
				ft_putchar(' ');
		}
	}
	else
	{
		if (!argv[0])
			ft_putchar('\0');
		else
			while (argv[index] != '\0')
			{
				ft_putstr(argv[index++]);
				if (argv[index] != NULL)
					ft_putchar(' ');
			}
		ft_putchar('\n');
	}
}
