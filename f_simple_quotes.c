/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_simple_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abambi <abambi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:12:03 by brattles          #+#    #+#             */
/*   Updated: 2021/10/17 16:57:28 by abambi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_simple_quotes(t_vars *vars, char **str)
{
	(*str)++;
	while (**str && !(**str == '\'' && *(*str - 1) != '\\'))
	{
		add_to_letters(vars, **str);
		(*str)++;
	}
	if (**str == '\'')
		(*str)++;
}
