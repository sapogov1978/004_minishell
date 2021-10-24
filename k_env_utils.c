/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 17:20:53 by brattles          #+#    #+#             */
/*   Updated: 2021/06/07 20:41:49 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_env_var(char *name, char **envp)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(name) + 1;
	while (envp[i] && env_strcmp(name, envp[i]))
		i++;
	if (envp[i])
		return (&envp[i][len]);
	else
		return (NULL);
}

int	env_strcmp(char *name, char *envvar)
{
	int	i;

	i = 0;
	while (name[i] == envvar[i])
		i++;
	if (name[i] == '\0' && envvar[i] == '=')
		return (0);
	else
		return (1);
}
