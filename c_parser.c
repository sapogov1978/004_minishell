/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:12:03 by brattles          #+#    #+#             */
/*   Updated: 2021/07/16 22:19:42 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_str(t_vars *vars)
{
	char	**arr_cmds;
	int		i;

	vars->cmds = NULL;
	arr_cmds = ft_split_ms(vars->buff, ';');
	if (arr_cmds == NULL)
		ft_panic(vars, "malloc error\n", 1);
	vars->arr_cmds_ptr = arr_cmds;
	i = 0;
	while (arr_cmds[i] != NULL)
		get_each_cmd(vars, arr_cmds[i++]);
	is_pipe_at_end(vars->buff, vars->cmds);
	free_strsplit(arr_cmds);
}

int	is_pipe_at_end(char *str, t_cmds *cmd_chain)
{
	int	len;

	len = ft_strlen(str) - 1;
	while (str[len] == ' ' && str[len] != str[0])
		len--;
	if (str[len] == '|')
	{
		set_pipe_flag(cmd_chain);
		return (1);
	}
	return (0);
}

void	set_pipe_flag(t_cmds *cmd_chain)
{
	while (cmd_chain->next != NULL)
		cmd_chain = cmd_chain->next;
	cmd_chain->flag = PIPE;
}

int	ft_b_err(char *bash, char *cmd, char *arg, char *msg)
{
	if (bash != NULL)
		ft_putstr_fd(bash, 2);
	if (cmd != NULL)
		ft_putstr_fd(cmd, 2);
	if (arg != NULL)
	{
		ft_putstr_fd(arg, 2);
		ft_putstr_fd(": ", 2);
	}
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	return (1);
}
