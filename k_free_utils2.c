/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_free_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abambi <abambi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 22:45:26 by brattles          #+#    #+#             */
/*   Updated: 2021/10/17 17:06:28 by abambi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_wordlists(t_wordlists **words)
{
	t_wordlists	*tmp;

	while (*words != NULL)
	{
		tmp = *words;
		free((*words)->str);
		*words = (*words)->next;
		free(tmp);
		tmp = NULL;
	}
}

void	free_letters(t_letters **one_word)
{
	t_letters	*tmp;
	t_letters	*res;

	tmp = *one_word;
	while (tmp)
	{
		res = tmp->next;
		free(tmp);
		tmp = res;
	}
	*one_word = NULL;
}
