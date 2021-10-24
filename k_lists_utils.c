/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_lists_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abambi <abambi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:12:03 by brattles          #+#    #+#             */
/*   Updated: 2021/10/17 17:07:11 by abambi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*letters_to_word(t_letters **abc, t_vars *vars)
{
	char		*res;
	t_letters	*tmp;
	int			i;	

	res = malloc(sizeof(char) * ((int)letters_size(*abc) + 1));
	if (res == NULL)
		ft_panic(vars, "malloc error", 1);
	i = 0;
	while (*abc)
	{
		tmp = *abc;
		res[i] = (*abc)->character;
		(*abc) = (*abc)->next;
		free(tmp);
		i++;
	}
	res[i] = '\0';
	return (res);
}

void	wordlist_add_back(t_wordlists **lst, t_wordlists *new)
{
	t_wordlists	*last;

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

void	add_to_wordlist(t_wordlists **head, t_letters **abc, t_vars *vars)
{
	t_wordlists	*new_word;
	char		*res;
	t_letters	*tmp;
	int			i;

	res = malloc(sizeof(char) * ((int)letters_size(*abc) + 1));
	if (res == NULL)
		ft_panic(vars, "malloc error", 1);
	i = 0;
	while (*abc)
	{
		tmp = *abc;
		res[i] = (*abc)->character;
		(*abc) = (*abc)->next;
		free(tmp);
		i++;
	}
	res[i] = '\0';
	new_word = malloc(sizeof(t_wordlists) * 1);
	if (new_word == NULL)
		ft_panic(vars, "malloc error", 1);
	new_word->str = res;
	new_word->next = NULL;
	wordlist_add_back(head, new_word);
}
