/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_double_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abambi <abambi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:12:03 by brattles          #+#    #+#             */
/*   Updated: 2021/10/17 16:57:00 by abambi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_spec_symbol(char *str)
{
	if ((*str == '$' && ft_isalnum(*(str + 1))) || \
		(*str == '$' && (*(str + 1) == '?')) || \
		*str == '\\' || *str == '\'' || *str == '\"')
		return (1);
	return (0);
}

void	parse_double_quotes(t_vars *vars, char **str)
{
	(*str)++;
	while (**str && !(**str == '\"' && *(*str - 1) != '\\'))
	{
		if (**str == '\'' || is_spec_symbol(*str) == 0)
		{
			add_to_letters(vars, **str);
			(*str)++;
		}
		else
		{
			if (**str == '\\')
				*str = parse_slash(vars, *str, 2);
			if (**str == '$' && *(*str + 1) == '?')
				*str = parse_dollar_what(vars, *str);
			else if (**str == '$' && *(*str + 1) != '?' && \
					ft_isalnum(*(*str + 1)))
				*str = parse_dollar_other(vars, *str);
		}
	}
	if (**str == '\"')
		(*str)++;
}
