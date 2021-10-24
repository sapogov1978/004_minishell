/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 23:50:11 by brattles          #+#    #+#             */
/*   Updated: 2021/06/30 01:27:11 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_last_code = 0;

int	main(int ac, char **av, char **envp)
{
	t_vars	vars;

	check_n_args(ac);
	init_struct(&vars);
	if (ac == 3 && ft_strlen(av[1]) == 2 && \
		av[1][0] == '-' && av[1][1] == 'c')
	{
		vars.buff = ft_strdup(av[2]);
		if (vars.buff == NULL)
			ft_panic(&vars, "malloc error\n", 1);
	}
	else if (ac == 3)
		ft_panic(&vars, "wrong args\n", 1);
	get_env_data(&vars, envp);
	shell_prompt_msg(&vars);
	clear_history();
	ft_panic(&vars, "", 1);
	return (g_last_code);
}

void	check_n_args(int ac)
{
	if (ac != 1 && ac != 3)
	{
		ft_putstr_fd("wrong number of args\n", 2);
		exit(-1);
	}
}

void	init_struct(t_vars *vars)
{
	vars->envir = NULL;
	vars->buff = NULL;
	vars->username = NULL;
	vars->cmds = NULL;
	vars->redir = NULL;
	vars->words = NULL;
	vars->one_word = NULL;
	vars->arr_cmds_ptr = NULL;
	vars->pipes_arr_ptr = NULL;
}

void	get_env_data(t_vars *vars, char **envp)
{
	char	*var_user;

	vars->envir = copy_environ(envp, vars);
	var_user = find_env_var("USER", vars->envir);
	vars->username = ft_strdup(var_user);
	if (vars->username == NULL)
		ft_panic(vars, "malloc error\n", 1);
}

char	**copy_environ(char **envp, t_vars *vars)
{
	int		i;
	int		len;
	char	**env_arr_copy;

	len = 0;
	while (envp[len])
		len++;
	env_arr_copy = malloc(sizeof(char *) * (len + 1));
	if (env_arr_copy == NULL)
		ft_panic(vars, "malloc error\n", 1);
	i = -1;
	while (envp[++i])
	{
		env_arr_copy[i] = ft_strdup(envp[i]);
		if (env_arr_copy[i] == NULL)
			ft_panic(vars, "malloc error\n", 1);
	}
	env_arr_copy[i] = 0;
	return (env_arr_copy);
}
