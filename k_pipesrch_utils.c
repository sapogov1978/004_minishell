/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_pipesrch_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abambi <abambi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:12:03 by brattles          #+#    #+#             */
/*   Updated: 2021/10/17 17:07:37 by abambi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	ft_detect_char(char *str)
{
	if (*str == '\"' && *(str - 1) != '\\')
		return (2);
	else if (*str == '\'' && *(str - 1) != '\\')
		return (1);
	return (0);
}

int	found_pipe(char *str)
{
	char	flag_begin;
	char	flag_end;

	while (*str)
	{
		flag_begin = ft_detect_char(str);
		if (flag_begin != 0)
		{
			while (*str)
			{
				str++;
				flag_end = ft_detect_char(str);
				if (flag_end == flag_begin)
				{
					flag_begin = 0;
					break ;
				}
			}
		}
		if (*str == '|')
			return (1);
		if (*str != '\0')
			str++;
	}
	return (0);
}
