/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_dollars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abambi <abambi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:12:03 by brattles          #+#    #+#             */
/*   Updated: 2021/10/05 20:19:56 by abambi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*parse_dollar_what(t_vars *vars, char *str)
{
	char	*code;
	int		i;

	code = ft_itoa(g_last_code);
	if (code == NULL)
		ft_panic(vars, "Error in parse dollar what", 1);
	i = -1;
	while (code[++i])
		add_to_letters(vars, code[i]);
	free(code);
	str += 2;
	return (str);
}

char	*isolate_var_name(t_vars *vars, char *str, int len)
{
	char	*name;
	int		i;

	name = malloc(sizeof(char) * (len + 1));
	if (name == NULL)
		ft_panic(vars, "parse dollar 1", 1);
	i = 0;
	while (len--)
	{
		name[i] = str[i];
		i++;
	}
	name[i] = '\0';
	return (name);
}

char	*parse_dollar_other(t_vars *vars, char *str)
{
	char	*name;
	char	*res;
	int		len;
	int		i;

	str++;
	len = 0;
	while (str[len] != '\0' && str[len] != ' ' && ft_isalnum(str[len]) == 1)
		len++;
	name = isolate_var_name(vars, str, len);
	str += len;
	res = find_env_var(name, vars->envir);
	free(name);
	if (res != NULL)
	{
		i = -1;
		while (res[++i])
			add_to_letters(vars, res[i]);
	}
	return (str);
}
