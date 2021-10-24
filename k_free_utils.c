/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_free_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abambi <abambi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 22:45:26 by brattles          #+#    #+#             */
/*   Updated: 2021/10/17 17:05:44 by abambi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_panic(t_vars *vars, char *msg, int return_code)
{
	free(vars->buff);
	vars->buff = NULL;
	free(vars->username);
	vars->username = NULL;
	free_strsplit(vars->envir);
	free_cmds(&vars->cmds);
	free_wordlists(&vars->words);
	free_letters(&vars->one_word);
	ft_putstr_fd(msg, 2);
	exit(return_code);
}

int	free_strsplit(char **all_path)
{
	int	i;

	i = 0;
	while (all_path[i])
		free(all_path[i++]);
	free(all_path);
	all_path = NULL;
	return (0);
}

void	free_cmd_params(char **cmd_params)
{
	int	i;

	i = 0;
	while (cmd_params[i])
	{
		free(cmd_params[i]);
		i++;
	}
	free(cmd_params);
	cmd_params = NULL;
}

void	free_cmds(t_cmds **cmds)
{
	t_cmds		*tmp;
	t_cmds		*res;

	tmp = *cmds;
	while (tmp)
	{
		free_cmd_params(tmp->arr_params);
		free_redirects(&tmp->redirect);
		res = tmp->next;
		free(tmp);
		tmp = res;
	}
	*cmds = NULL;
}

void	free_redirects(t_redirect **redir)
{
	t_redirect	*tmp;

	while (*redir != NULL)
	{
		tmp = *redir;
		free((*redir)->one_param);
		*redir = (*redir)->next;
		free(tmp);
		tmp = NULL;
	}
}
