/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_slash2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abambi <abambi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:12:03 by brattles          #+#    #+#             */
/*   Updated: 2021/10/17 17:00:44 by abambi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*parse_simple_quote_inside_duoquotes(char *s, int i, t_vars *vars)
{
	if (i == 1)
	{
		add_slashes(vars, 1, '\'');
		s += i + 1;
		return (s);
	}
	if (i % 2 == 0)
		add_slashes(vars, i / 2, '\'');
	else
		add_slashes(vars, (i / 2) + 1, '\'');
	s += i + 1;
	return (s);
}

char	*parse_shielded_duoquote(char *s, int i, t_vars *vars)
{
	add_slashes(vars, i / 2, '\"');
	s += i + 1;
	return (s);
}

char	*parse_just_slashes(char *s, int i, t_vars *vars)
{
	if (i % 2 == 0)
	{
		add_slashes(vars, i / 2, 0);
		s += i;
	}
	else if (i % 2 != 0)
		ft_panic(vars, "Error: subject: \"Not interpret unclosed quotes or \
unspecified special characters like \\ or ;\"\n", 1);
	return (s);
}
