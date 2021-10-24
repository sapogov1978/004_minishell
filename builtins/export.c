/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:48:52 by brattles          #+#    #+#             */
/*   Updated: 2021/10/19 00:08:37 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_export(char *str, t_vars *vars)
{
	int	res;

	if (str == NULL)
		res = ft_print_env(vars->envir, vars, "declare -x ");
	else
		res = export_values(str, vars);
	return (res);
}

int	export_values(char *str, t_vars *vars)
{
	char	*name;
	char	*value;
	int		len;

	name = get_name(str);
	if (name == NULL)
		return (1);
	len = ft_strlen(name) + 1;
	value = get_value(&str[len]);
	if (value == NULL)
	{
		free(name);
		return (1);
	}
	if (rewrite_envvar(name, value, vars->envir) == 0)
		insert_envvar(vars, name, value, vars->envir);
	free(name);
	free(value);
	return (0);
}

char	*get_name(char *str)
{
	int	i;

	i = 0;
	if (ft_isdigit(str[0]) || str[0] == '=')
	{
		ft_b_err("bash: ", "export: ", str, "not a valid identifier");
		return (NULL);
	}
	while (str[i] != '=' && \
			(ft_isalpha(str[0]) || ft_isdigit(str[0]) || str[0] == '_'))
		i++;
	if (str[i] == '=')
		return (ft_substr(str, 0, i));
	else
		return (NULL);
}

char	*get_value(char *str)
{
	if (!str[0] || str[0] == ' ')
		return (NULL);
	if (str[0] == '\'' || str[0] == '\"')
		return (ft_strtrim(str, &str[0]));
	else
		return (ft_strdup(str));
}
