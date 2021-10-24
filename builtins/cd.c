/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 19:01:11 by brattles          #+#    #+#             */
/*   Updated: 2021/10/19 00:08:37 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_env_value(char *value, t_vars *vars)
{
	if (value == NULL)
		ft_panic(vars, "malloc error\n", 1);
	ft_export(value, vars);
	free(value);
}

int	ft_cd(char **arr_params, t_vars *vars)
{
	char	s[PATH_MAX];
	int		dir;

	if (arr_params[1] == NULL)
		dir = chdir(find_env_var("HOME", vars->envir));
	else if (*arr_params[1] == '-')
		dir = chdir(find_env_var("OLDPWD", vars->envir));
	else
		dir = chdir(arr_params[1]);
	if (dir == -1)
	{
		ft_b_err("bash: ", "cd: ", arr_params[1], strerror(errno));
		return (1);
	}
	set_env_value((ft_strjoin("OLDPWD=", \
					find_env_var("PWD", vars->envir))), vars);
	set_env_value((ft_strjoin("PWD=", getcwd(s, PATH_MAX))), vars);
	return (0);
}
