/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:48:52 by brattles          #+#    #+#             */
/*   Updated: 2021/06/21 21:44:21 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_print_env(char **argv, t_vars *vars, char *prefix)
{
	int	i;

	(void)argv;
	i = -1;
	if (prefix)
	{
		while (vars->envir[++i])
		{
			ft_putstr_fd(prefix, 1);
			ft_putstr_fd(vars->envir[i], 1);
			write(1, "\n", 1);
		}		
	}
	else
	{
		while (vars->envir[++i])
		{
			ft_putstr_fd(vars->envir[i], 1);
			write(1, "\n", 1);
		}
	}
	return (0);
}
