/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_parser2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abambi <abambi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:12:03 by brattles          #+#    #+#             */
/*   Updated: 2021/10/18 23:24:35 by abambi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_params(char *str, t_vars *vars)
{
	int	redir_type;

	vars->words = NULL;
	skip_spaces(&str);
	while (*str)
	{
		vars->one_word = NULL;
		while (*str && *str != ' ' && *str != '>' && *str != '<')
			str = main_parsing(str, vars);
		if (*str == '>' || *str == '<')
		{
			if (vars->one_word != NULL)
				add_to_wordlist(&vars->words, &vars->one_word, vars);
			redir_type = go_through_redirs(&str, vars);
			vars->one_word = NULL;
			while (*str && *str != ' ' && *str != '>' && *str != '<')
				str = main_parsing(str, vars);
			set_collected_info(vars, redir_type);
		}
		else
			add_to_wordlist(&vars->words, &vars->one_word, vars);
		skip_spaces(&str);
	}
	return (convert_to_char_zz(&vars->words, vars));
}

void	set_heredoc(t_vars *vars)
{
	vars->one_word = NULL;
	add_to_letters(vars, '<');
	add_to_letters(vars, '<');
	add_to_wordlist(&vars->words, &vars->one_word, vars);
}

void	set_collected_info(t_vars *vars, int redir_type)
{
	if (redir_type == HEREDOC)
		add_to_wordlist(&vars->words, &vars->one_word, vars);
	else
		set_redir_params(vars, &vars->one_word, redir_type);
}

void	set_redir_params(t_vars *vars, t_letters **abc, int flag)
{
	t_redirect	*new_redir;

	new_redir = (t_redirect *)malloc(sizeof(t_redirect));
	if (new_redir == NULL)
		ft_panic(vars, "malloc error", 1);
	new_redir->redir_type = flag;
	if (flag == 0)
		new_redir->one_param = NULL;
	else
		new_redir->one_param = letters_to_word(abc, vars);
	new_redir->next = NULL;
	redir_addback(&vars->redir, new_redir);
}

void	redir_addback(t_redirect **lst, t_redirect *new)
{
	t_redirect	*last;

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
