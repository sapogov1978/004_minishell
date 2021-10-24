/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_exec2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 07:07:35 by brattles          #+#    #+#             */
/*   Updated: 2021/10/19 22:36:41 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	redirection(t_vars *vars)
{
	int			fd;
	t_redirect	*tmp;
	int			return_id;

	fd = 0;
	tmp = vars->cmds->redirect;
	while (tmp != NULL)
	{
		if (fd > 0)
			close(fd);
		if (tmp->redir_type == READ_FROM)
			fd = read_from(tmp, vars);
		else
			fd = write_to(tmp, vars);
		tmp = tmp->next;
	}
	return_id = execution(vars);
	return (return_id);
}

int	read_from(t_redirect *redir, t_vars *vars)
{
	int	fd;

	fd = open(redir->one_param, O_RDONLY);
	if (fd > 0)
		dup2(fd, STDIN);
	else
	{
		ft_b_err("bash: ", 0x0, redir->one_param, "No such file or directory");
		ft_panic(vars, "", 1);
	}
	return (fd);
}

int	write_to(t_redirect *redir, t_vars *vars)
{
	int	fd;

	if (redir->redir_type == APPEND)
		fd = open(redir->one_param, O_RDWR | O_APPEND | O_CREAT, 00644);
	else if (redir->redir_type == REWRITE)
		fd = open(redir->one_param, O_RDWR | O_TRUNC | O_CREAT, 00644);
	if (fd > 0)
		dup2(fd, STDOUT);
	else
	{
		ft_b_err("bash: ", 0x0, redir->one_param, "Permission denied");
		ft_panic(vars, "error in open", 1);
	}
	return (fd);
}

int	execution(t_vars *vars)
{
	if (!ft_strcmp(vars->cmds->arr_params[0], "cd"))
		return (ft_cd(vars->cmds->arr_params, vars));
	else if (!ft_strcmp(vars->cmds->arr_params[0], "echo"))
		return (ft_echo(&vars->cmds->arr_params[1]));
	else if (!ft_strcmp(vars->cmds->arr_params[0], "env"))
		return (ft_print_env(vars->cmds->arr_params, vars, NULL));
	else if (!ft_strcmp(vars->cmds->arr_params[0], "exit"))
		return (ft_exit_program(vars));
	else if (!ft_strcmp(vars->cmds->arr_params[0], "export"))
		return (ft_export(vars->cmds->arr_params[1], vars));
	else if (!ft_strcmp(vars->cmds->arr_params[0], "<<"))
		return (ft_heredoc(vars->cmds->arr_params[1], vars));
	else if (!ft_strcmp(vars->cmds->arr_params[0], "pwd"))
		return (ft_pwd());
	else if (!ft_strcmp(vars->cmds->arr_params[0], "unset"))
		return (ft_unset(vars->cmds->arr_params[1], vars));
	return (launch_other_cmds(vars->cmds->arr_params, vars));
	return (1);
}
