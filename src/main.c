/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 07:40:57 by monoue            #+#    #+#             */
/*   Updated: 2021/02/17 15:48:18 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_last_exit_status = 0;

static void	main_loop(t_list *envp)
{
	int			ret;
	char		*line;

	ft_putstr(PROMPT);
	set_signal_handlers();
	ret = get_next_line(STDIN_FILENO, &line);
	if (ret == ERROR)
		exit_err_msg(MALLOC_ERR);
	if (ret == FILE_END)
	{
		put_farewell_greeting();
		exit(EXIT_SUCCESS);
	}
	if (str_is_of_spaces(line) || put_message_if_syntax_error(line))
	{
		SAFE_FREE(line);
		return ;
	}
	process_command_line(line, envp);
}

int			main(void)
{
	t_list		*envp;

	put_welcome_greeting();
	envp = get_env_list();
	while (42)
		main_loop(envp);
}
