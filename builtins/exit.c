/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 07:19:51 by brattles          #+#    #+#             */
/*   Updated: 2021/06/08 23:31:46 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exit_program(t_vars *vars)
{
	int	arg_n;
	int	res;

	arg_n = num_lines(vars->cmds->arr_params);
	res = 0;
	if (arg_n == 1)
	{
		write(1, "exit\n", 5);
		ft_putstr_fd("\nHasta la vista, baby\n", 1);
		res = 0;
	}
	else if (arg_n == 2)
		res = analyze_exit_arg(vars);
	else
	{
		ft_b_err("bash: ", "exit: ", NULL, "too many arguments");
		res = 1;
	}
	ft_panic(vars, "", res);
	return (res);
}

int	analyze_exit_arg(t_vars *vars)
{
	char	*str;
	int		not_digit;
	int		res;

	str = vars->cmds->arr_params[1];
	not_digit = 0;
	while (*str)
	{
		if (!ft_isdigit(*str))
			not_digit++;
		str++;
	}
	if (not_digit)
	{
		ft_b_err("bash: ", "exit: ", vars->cmds->arr_params[1], \
			"numeric argument required");
		res = 255;
	}
	else
	{
		res = ft_atoi(vars->cmds->arr_params[1]);
		if (res > 255)
			res = 0;
	}
	return (res);
}
