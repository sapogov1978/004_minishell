/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_home_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abambi <abambi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:12:03 by brattles          #+#    #+#             */
/*   Updated: 2021/10/10 16:06:48 by abambi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*parse_home_path(t_vars *vars, char *str)
{
	char	*res;
	int		i;

	i = -1;
	if (*(str + 1) == '/' || *(str + 1) == ' ' || *(str + 1) == '\0')
	{
		str++;
		res = find_env_var("HOME", vars->envir);
		while (res[++i])
			add_to_letters(vars, res[i]);
	}
	else
	{
		str++;
		add_to_letters(vars, '~');
	}
	return (str);
}
