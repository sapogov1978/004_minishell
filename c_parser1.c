/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_parser1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:12:03 by brattles          #+#    #+#             */
/*   Updated: 2021/10/19 21:30:36 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmds	*get_each_cmd(t_vars *vars, char *arr_cmds)
{
	vars->redir = NULL;
	if (found_pipe(arr_cmds) == 0)
		isolate_cmd_params(vars, arr_cmds, COMMAND);
	else
		pipe_branch(vars, arr_cmds);
	return (vars->cmds);
}

void	pipe_branch(t_vars *vars, char *arr_cmds)
{
	char	**pipes_arr;
	int		arg_n;
	int		j;

	pipes_arr = ft_split_ms(arr_cmds, '|');
	if (pipes_arr == NULL)
		ft_panic(vars, "malloc error", 1);
	vars->pipes_arr_ptr = pipes_arr;
	j = -1;
	arg_n = num_lines(pipes_arr);
	while (++j < (arg_n - 1))
		isolate_cmd_params(vars, pipes_arr[j], PIPE);
	isolate_cmd_params(vars, pipes_arr[j], COMMAND);
	free_strsplit(pipes_arr);
}

void	isolate_cmd_params(t_vars *vars, char *arr, int flag)
{
	char	**cmd_params;
	t_cmds	*cmd_new;
	char	*arr_copy;

	arr_copy = arr;
	skip_spaces(&arr_copy);
	if (*arr_copy == '\0')
		vars->cmds = NULL;
	else
	{
		cmd_params = get_params(arr, vars);
		cmd_new = set_params(cmd_params, flag, vars->redir, vars);
		if (cmd_new == NULL)
			ft_panic(vars, "malloc error\n", 1);
		cmd_addback(&vars->cmds, cmd_new);
	}
}

t_cmds	*set_params(char **cmd_params, int flag, \
			t_redirect *redir, t_vars *vars)
{
	t_cmds	*new_cmd;

	new_cmd = malloc(sizeof(t_cmds) * 1);
	if (!new_cmd)
		ft_panic(vars, "malloc error\n", 1);
	new_cmd->arr_params = cmd_params;
	new_cmd->flag = flag;
	new_cmd->redirect = redir;
	return (new_cmd);
}

void	cmd_addback(t_cmds **lst, t_cmds *new)
{
	t_cmds	*last;

	if (*lst == NULL)
	{
		*lst = new;
		(*lst)->next = NULL;
		return ;
	}
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = new;
	new->next = NULL;
}
