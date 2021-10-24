/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_handlers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 21:59:03 by brattles          #+#    #+#             */
/*   Updated: 2021/06/22 23:03:37 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Ctrl C
*/

void	handler_sigint(int sig)
{
	if (sig == SIGINT)
	{
		ft_putstr_fd("\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		(void)sig;
		g_last_code = 130;
	}
}

/*
** Ctrl D
*/

void	handler_sigquit(int sig)
{
	if (sig == SIGQUIT)
	{
		rl_on_new_line();
		rl_redisplay();
		write (1, "  \b\b", 4);
		(void)sig;
		g_last_code = 0;
	}
}

/*
** Ctrl \
** does nothing
*/
