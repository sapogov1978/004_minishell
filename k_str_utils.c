/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 22:45:26 by brattles          #+#    #+#             */
/*   Updated: 2021/06/29 23:57:33 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	skip_spaces(char **str)
{
	while (**str == ' ')
		(*str)++;
}

int	num_lines(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);
}

int	letters_size(t_letters *abc)
{
	int		i;

	i = 0;
	while (abc != NULL)
	{
		abc = abc->next;
		i++;
	}
	return (i);
}

int	wordlists_size(t_wordlists *wordlists)
{
	int	i;

	i = 0;
	while (wordlists != NULL)
	{
		wordlists = wordlists->next;
		i++;
	}
	return (i);
}

char	**convert_to_char_zz(t_wordlists **head, t_vars *vars)
{
	int			i;
	char		**str;
	t_wordlists	*tmp;

	str = malloc(sizeof(char *) * (wordlists_size(*head) + 1));
	if (str == NULL)
		ft_panic(vars, "malloc error", 1);
	i = 0;
	while (*head != NULL)
	{
		tmp = *head;
		str[i] = (*head)->str;
		*head = (*head)->next;
		free(tmp);
		i++;
	}
	str[i] = NULL;
	return (str);
}
