/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 17:41:05 by sperrin           #+#    #+#             */
/*   Updated: 2021/02/26 16:58:19 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool			digits_num_is_over_llong_max(const char *str)
{
	size_t	index;

	index = 0;
	if (str[index] == '+' || str[index] == '-')
		index++;
	while (str[index] == '0')
		index++;
	return (ft_strlen(&str[index]) > LLONG_MAX_DIGITS);
}

static bool			str_is_within_llong(const char *str)
{
	bool				sign;
	unsigned long long	n;
	size_t				index;

	index = 0;
	if (digits_num_is_over_llong_max(str))
		return (false);
	sign = false;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			sign = true;
		index++;
	}
	n = ft_atoull(&str[index]);
	if (n == 0)
		return (true);
	if (sign)
		n--;
	return (n <= LLONG_MAX);
}

bool				str_is_within_int(const char *str)
{
	bool				sign;
	unsigned long long	n;
	size_t				index;

	index = 0;
	if (digits_num_is_over_llong_max(str))
		return (false);
	sign = false;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			sign = true;
		index++;
	}
	n = ft_atoull(&str[index]);
	if (n == 0)
		return (true);
	if (sign)
		n--;
	return (n <= INT_MAX);
}

bool				str_is_valid_num(char *str)
{
	size_t	index;

	index = 0;
	while (str[index] == ' ')
		index++;
	if ((str[index] == '-' && str[index + 1] != '\0')
	|| (str[index] == '+' && str[index + 1] != '\0'))
		index++;
	if (!ft_str_is_numeric(&str[index])) //|| (ft_strcmp(str, "") == 0))
		return (false);
	return (str_is_within_llong(str));
}

int					exit_minishell(char **argv)
{
	int				nbr;
	int				exit_nbr;
	const size_t	argv_num = ft_count_strs((const char**)argv);


	if (argv_num == 1)
	{
		ft_putendl_err("exit");
		put_farewell_greeting();
		exit(EXIT_SUCCESS);
	}
	if (!str_is_valid_num(argv[1]))
		put_error_numeric(argv[1]);
	if (argv_num > 2)
	{
		ft_putendl_err("exit\n");
		ft_putendl("bash: exit: too many arguments");
		return (EXIT_FAILURE);
	}
	nbr = ft_atoll(argv[1]);
	exit_nbr = ((nbr % 256) + 256) % 256;
	ft_putendl_err("exit");
	exit(exit_nbr);
	return (EXIT_SUCCESS);
}
