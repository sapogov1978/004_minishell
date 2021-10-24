/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_split_ms2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 14:13:39 by abambi            #+#    #+#             */
/*   Updated: 2021/10/19 21:26:53 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_start_errors(char *s)
{
	if (s == NULL)
	{
		syntax_error(4);
		exit(2);
	}
	if (s[0] == ';' && s[1] == '\0')
	{
		syntax_error(3);
		exit(2);
	}
	else if (s[0] == '|' && s[1] == '\0')
	{
		syntax_error(5);
		exit(2);
	}
}

void	check_split_errors2(char *s)
{
	int	i;

	i = 0;
	if (s[i] == ';' && s[i + 1] == ';')
	{
		syntax_error(6);
		exit(2);
	}
	if (s[i] == '|' && s[i + 1] == '|')
	{
		syntax_error(7);
		exit(2);
	}
}

void	check_split_errors(char *s, char c)
{
	char	flag_begin;
	int		i;

	i = 0;
	while (s[i])
	{
		flag_begin = ft_smart_detect_char(&s[i], i);
		if (flag_begin != 0)
		{
			while (s[++i])
			{
				if (ft_smart_detect_char(&s[i], i) == flag_begin)
					break ;
			}
		}
		if (s[i] == c && s[i + 1] == c)
			break ;
		i++;
	}
	check_split_errors2(s);
}

char	ft_smart_detect_char(char *str, int i)
{
	if (*str == '\"' && i == 0)
		return (2);
	else if (*str == '\"' && *(str - 1) != '\\')
		return (2);
	else if (*str == '\'' && i == 0)
		return (1);
	else if (*str == '\'' && *(str - 1) != '\\')
		return (1);
	return (0);
}
