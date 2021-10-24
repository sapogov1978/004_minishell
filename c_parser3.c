/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_parser3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abambi <abambi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:12:03 by brattles          #+#    #+#             */
/*   Updated: 2021/10/18 23:28:22 by abambi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_newline_err(char *s)
{
	while (*s == ' ')
		s++;
	if (*s == '\0')
		return (1);
	return (0);
}

int	count_chars(char *s, char c)
{
	int	i;

	if (c == '\0' && s[0] == c)
		return (1);
	else if (c == '\0' && s[0] != c)
		return (0);
	i = 0;
	while (s[i] == c)
		i++;
	return (i);
}

int	find_check_redirs2(char **str, char c, int res)
{
	if (res == 2 && c == '<')
		res = HEREDOC;
	else if (res == 2 && c == '>')
	{
		res = APPEND;
		if (**str == '<' && *(*str + 1) != '<')
			return (syntax_error(0));
		else if (**str == '<' && *(*str + 1) == '<')
			return (syntax_error(1));
	}
	else if (res >= 3 && c == '>')
		return (syntax_error(2));
	else if (res >= 3 && c == '<')
		return (syntax_error(0));
	return (res);
}

int	find_check_redirs(char **str, char c)
{
	int	res;

	res = count_chars(*str, c);
	*str += res;
	if (is_newline_err(*str) == 1)
		return (syntax_error(4));
	if (res == 1 && c == '<')
	{
		res = READ_FROM;
		if (**str == '>' && (*str)++)
			res = REWRITE;
	}
	else if (res == 1 && c == '>')
	{
		res = REWRITE;
		if (**str == '<' && *(*str + 1) != '<')
			return (syntax_error(0));
		else if (**str == '<' && *(*str + 1) == '<')
			return (syntax_error(1));
	}
	else if (res >= 2)
		res = find_check_redirs2(str, c, res);
	return (res);
}

int	go_through_redirs(char **str, t_vars *vars)
{
	int	res;

	if (**str == '>' || **str == '<')
		res = find_check_redirs(str, **str);
	else
		res = 0;
	skip_spaces(str);
	if (res == HEREDOC)
		set_heredoc(vars);
	return (res);
}
