/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 19:01:11 by brattles          #+#    #+#             */
/*   Updated: 2021/06/21 21:02:14 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_n_flag(char **arr_params)
{
	if (*arr_params && ft_strcmp(*arr_params, "-n") == 0)
		return (1);
	else
		return (0);
}

int	ft_echo(char **arr_params)
{
	int	nflag;

	nflag = find_n_flag(arr_params);
	if (nflag == 1)
		arr_params += 1;
	while (*arr_params != NULL)
	{
		ft_putstr_fd(*arr_params, 1);
		arr_params++;
		if (*arr_params)
			ft_putchar_fd(' ', 1);
	}
	if (nflag != 1)
		ft_putchar_fd('\n', 1);
	return (0);
}
