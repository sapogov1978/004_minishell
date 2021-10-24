/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_slash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abambi <abambi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:12:03 by brattles          #+#    #+#             */
/*   Updated: 2021/10/17 17:00:28 by abambi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_slashes(t_vars *vars, int count, char c)
{
	int	i;

	i = -1;
	while (++i < count)
		add_to_letters(vars, '\\');
	if (c != '\0')
		add_to_letters(vars, c);
}

char	*parse_shielded_dollar_what(char *s, int i, t_vars *vars)
{
	if (i % 2 == 0)
	{
		add_slashes(vars, i / 2, 0);
		s += i;
	}
	else
	{
		add_slashes(vars, i / 2, '$');
		s += i + 1;
	}
	return (s);
}

char	*parse_shielded_dollar_other(char *s, int i, t_vars *vars)
{
	if (i % 2 == 0)
	{
		add_slashes(vars, i / 2, 0);
		s += i;
	}
	else
	{
		add_slashes(vars, i / 2, '$');
		s += i + 1;
	}
	return (s);
}

char	*parse_shielded_simple_quote(char *s, int i, t_vars *vars)
{
	add_slashes(vars, i / 2, '\'');
	s += i + 1;
	return (s);
}

char	*parse_slash(t_vars *vars, char *s, int flag)
{
	int	i;

	i = count_chars(s, '\\');
	if (s[i] == '$' && s[i + 1] == '?')
		s = parse_shielded_dollar_what(s, i, vars);
	else if (s[i] == '$' && s[i + 1] != '?' && ft_isalnum(s[i + 1]))
		s = parse_shielded_dollar_other(s, i, vars);
	else if (s[i] == '\'' && flag == 0)
		s = parse_shielded_simple_quote(s, i, vars);
	else if (s[i] == '\'' && flag == 2)
		s = parse_simple_quote_inside_duoquotes(s, i, vars);
	else if (s[i] == '\"')
		s = parse_shielded_duoquote(s, i, vars);
	else
		s = parse_just_slashes(s, i, vars);
	return (s);
}
