/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abambi <abambi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 07:19:51 by brattles          #+#    #+#             */
/*   Updated: 2021/10/17 17:19:38 by abambi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_unset(char *str, t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->envir[i] && env_strcmp(str, vars->envir[i]))
		i++;
	if (vars->envir[i])
	{
		free(vars->envir[i]);
		vars->envir[i] = vars->envir[i + 1];
		while (vars->envir[++i])
			vars->envir[i] = vars->envir[i + 1];
	}
	return (0);
}
