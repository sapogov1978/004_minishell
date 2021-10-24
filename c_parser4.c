/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_parser4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:12:03 by brattles          #+#    #+#             */
/*   Updated: 2021/10/19 23:40:57 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*main_parsing(char *str, t_vars *vars)
{
	if (*str == '~')
		str = parse_home_path(vars, str);
	if (*str == '\'' && *(str - 1) != '\\')
		parse_simple_quotes(vars, &str);
	if (*str == '\"' && *(str - 1) != '\\')
		parse_double_quotes(vars, &str);
	if (*str == '\\')
		str = parse_slash(vars, str, 0);
	if (*str == '$' && *(str + 1) == '?')
		str = parse_dollar_what(vars, str);
	if (*str == '$' && *(str + 1) != '?' && ft_isalnum(*(str + 1)))
		str = parse_dollar_other(vars, str);
	if (*str != '\0' && is_spec_symbol(str) == 0 && \
			*str != ' ' && *str != '>' && *str != '<')
		add_to_letters(vars, *str++);
	return (str);
}

void	add_to_letters(t_vars *vars, char c)
{
	t_letters	*new;

	new = malloc(sizeof(t_letters) * 1);
	if (new == NULL)
		ft_panic(vars, "malloc error", 1);
	new->character = c;
	new->next = NULL;
	letter_addback(&vars->one_word, new);
}

void	letter_addback(t_letters **lst, t_letters *new)
{
	t_letters	*last;

	if (*lst == NULL)
	{
		*lst = new;
		(*lst)->next = NULL;
		return ;
	}
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = new;
	new->next = NULL;
}

int	syntax_error(int flag)
{
	if (flag == 0)
		ft_b_err("bash: ", 0x0, 0x0, "syntax error near unexpected token '<'");
	else if (flag == 1)
		ft_b_err("bash: ", 0x0, 0x0, "syntax error near unexpected token '<<'");
	else if (flag == 2)
		ft_b_err("bash: ", 0x0, 0x0, "syntax error near unexpected token '>'");
	else if (flag == 3)
		ft_b_err("bash: ", 0x0, 0x0, "syntax error near unexpected token ';'");
	else if (flag == 4)
		ft_b_err("bash: ", 0x0, 0x0, \
		"syntax error near unexpected token 'newline'");
	else if (flag == 5)
		ft_b_err("bash: ", 0x0, 0x0, "syntax error near unexpected token '|'");
	else if (flag == 6)
		ft_b_err("bash: ", 0x0, 0x0, "syntax error near unexpected token ';;'");
	else if (flag == 7)
		ft_b_err("bash: ", 0x0, 0x0, "syntax error near unexpected token '||'");
	g_last_code = 2;
	return (0);
}
