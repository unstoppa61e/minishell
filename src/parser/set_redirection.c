/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_redirection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperrin <sperrin@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 14:44:55 by monoue            #+#    #+#             */
/*   Updated: 2021/03/11 23:31:23 by sperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_open_flags(t_type type)
{
	if (type == TYPE_INPUT)
		return (O_RDONLY);
	if (type == TYPE_OUTPUT)
		return (O_WRONLY | O_CREAT | O_TRUNC);
	if (type == TYPE_APPEND)
		return (O_WRONLY | O_CREAT | O_APPEND);
	return (ERROR);
}

static bool	is_bad_fd(int fd)
{
	if (fd == OVER_INT_MAX)
		return (true);
	return (fd > UCHAR_MAX);
}

static void	put_bad_fd_message(int fd)
{
	const char	*out_of_range = "file descriptor out of range";
	const char	*bad_fd = "Bad file descriptor";
	char		*num_str;

	if (fd == OVER_INT_MAX)
		put_bash_err_msg(out_of_range, bad_fd);
	else
	{
		num_str = ft_itoa(fd);
		put_bash_err_msg(num_str, bad_fd);
		SAFE_FREE(num_str);
	}
}

int			set_redirection(t_redirection_set *set, t_fd *fds, int fild_fd)
{
	const t_type	type = set->type;

	if (!set->filename)
	{
		put_bash_err_msg(set->filename, "bash: : No such file or directory");
		return (ERROR);
	}
	fild_fd = open(set->filename, get_open_flags(type), OPEN_MODE);
	if (fild_fd == ERROR || is_bad_fd(set->designated_fd))
	{
		if (fild_fd == ERROR)
			put_bash_err_msg(set->filename, strerror(errno));
		else
			put_bad_fd_message(set->designated_fd);
		g_last_exit_status = EXIT_FAILURE;
		return (ERROR);
	}
	close(set->designated_fd);
	if (type == TYPE_INPUT)
		dup2(fds->input, set->designated_fd);
	else
		dup2(fds->output, set->designated_fd);
	dup2(fild_fd, set->designated_fd);
	close(fild_fd);
	return (SUCCESS);
}
