/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 07:07:35 by brattles          #+#    #+#             */
/*   Updated: 2021/07/18 23:58:53 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	start_program(t_vars *vars)
{
	int		fd_in;
	int		return_id;
	t_cmds	*cmds_copy;

	cmds_copy = vars->cmds;
	fd_in = dup(STDIN);
	return_id = 0;
	while (vars->cmds != NULL)
	{
		return_id = start_cmd(vars, fd_in);
		vars->cmds = vars->cmds->next;
	}
	vars->cmds = cmds_copy;
	return (return_id);
}

int	start_cmd(t_vars *vars, int fd_in)
{
	int	return_id;

	if (vars->cmds->flag == COMMAND)
	{
		return_id = do_each_cmd(vars);
		dup2(fd_in, STDIN);
	}
	else if (vars->cmds->flag == PIPE)
	{
		return_id = fork_dup(vars);
	}
	return (return_id);
}

int	do_each_cmd(t_vars *vars)
{
	int	return_id;
	int	fd_out;
	int	fd_in;

	return_id = 0;
	fd_in = dup(STDIN);
	fd_out = dup(STDOUT);
	if (vars->cmds->redirect != NULL)
		return_id = redirection(vars);
	else
		return_id = execution(vars);
	dup2(fd_in, STDIN);
	dup2(fd_out, STDOUT);
	return (return_id);
}

int	fork_dup(t_vars *vars)
{
	int		fd_buf[2];
	int		return_id;
	pid_t	id;

	return_id = 1;
	if (pipe(fd_buf) == -1)
		ft_panic(vars, "pipe error\n", 1);
	id = fork();
	if (id == -1)
		ft_panic(vars, "fork error\n", 1);
	else
		return_id = start_processes(id, fd_buf, vars);
	return (return_id);
}

int	start_processes(int id, int fd_buf[2], t_vars *vars)
{
	int	return_id;

	return_id = 1;
	if (id == 0)
	{
		close(fd_buf[READ]);
		dup2(fd_buf[WRITE], STDOUT);
		return_id = do_each_cmd(vars);
		exit(0);
	}
	else
	{
		waitpid(0, &return_id, WUNTRACED);
		close(fd_buf[WRITE]);
		dup2(fd_buf[READ], STDIN);
	}
	return (return_id);
}
