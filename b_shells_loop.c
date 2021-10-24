/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_shells_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abambi <abambi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 07:18:15 by brattles          #+#    #+#             */
/*   Updated: 2021/10/17 16:36:20 by abambi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	shell_prompt_msg(t_vars *vars)
{
	vars->cmds = NULL;
	while (1)
	{
		signal(SIGQUIT, handler_sigquit);
		signal(SIGINT, handler_sigint);
		if (vars->buff == NULL)
			get_next_line_ms(vars);
		parse_str(vars);
		free(vars->buff);
		vars->buff = NULL;
		if (vars->cmds != NULL)
			g_last_code = start_program(vars);
		free_cmds(&vars->cmds);
	}
}

void	get_next_line_ms(t_vars *vars)
{
	char	*input_start;

	input_start = ft_strjoin(vars->username, "$> ");
	vars->buff = readline(input_start);
	free(input_start);
	if (vars->buff && vars->buff[0])
		add_history(vars->buff);
	else if (vars->buff == NULL)
	{
		write(1, "exit\n", 5);
		ft_panic(vars, "", 0);
	}
}
