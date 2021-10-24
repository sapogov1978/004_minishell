/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abambi <abambi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:48:52 by brattles          #+#    #+#             */
/*   Updated: 2021/10/11 22:34:10 by abambi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	rewrite_envvar(char *name, char *value, char **envp)
{
	char	*new;
	int		i;

	i = 0;
	while (envp[i] && env_strcmp(name, envp[i]))
		i++;
	if (envp[i])
	{
		new = compose_envvar(name, value);
		if (new)
		{
			free(envp[i]);
			envp[i] = new;
			return (1);
		}
		else
			return (0);
	}
	return (0);
}

char	*compose_envvar(char *name, char *value)
{
	char	*tmp;
	char	*res;

	tmp = ft_strjoin(name, "=");
	if (tmp == NULL)
		return (NULL);
	res = ft_strjoin(tmp, value);
	if (res == NULL)
	{
		free(tmp);
		return (NULL);
	}
	free(tmp);
	return (res);
}

char	**insert_envvar(t_vars *vars, char *name, \
			char *value, char **envp)
{
	int		len;
	char	**new_envp;
	int		i;

	len = num_lines(envp);
	new_envp = malloc(sizeof(char *) * (len + 2));
	if (new_envp == NULL)
		ft_panic(vars, "malloc error\n", 1);
	new_envp[len + 1] = NULL;
	i = -1;
	while (++i < len - 1)
		new_envp[i] = envp[i];
	new_envp[i] = compose_envvar(name, value);
	new_envp[i + 1] = envp[i];
	if (new_envp[i] == NULL)
		return (NULL);
	free(vars->envir);
	vars->envir = new_envp;
	return (new_envp);
}
