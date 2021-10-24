/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 22:50:19 by brattles          #+#    #+#             */
/*   Updated: 2021/06/06 23:11:41 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	token_error(char *err)
{
	ft_putstr_fd("-bash: syntax error near unexpected token '", 2);
	write(2, err, ft_strlen(err));
	write(2, "'\n", 2);
	return (0);
}

void	which_token_err(char *buf)
{
	if (buf[0] == ';' && buf[1] == ';')
		token_error(";;");
	else if (buf[0] == ';' && buf[1] != ';')
		token_error(";");
	else if (buf[0] == '|' && buf[1] == '|')
		token_error("||");
	else
		token_error("|");
}

int	print_file_error(char *s)
{
	write(2, "bash: -cd: ", 11);
	write(2, s, ft_strlen(s));
	write(2, ": No such file or directory\n", 28);
	return (1);
}

int	export_error(char *key, char *value)
{
	printf("minishell: export: `%s=%s': not a valid identifier\n", key, value);
	return (0);
}

int	ft_b_err(char *bash, char *cmd, char *arg, char *msg)
{
	if (bash != NULL)
		ft_putstr_fd(bash, 2);
	if (cmd != NULL)
		ft_putstr_fd(cmd, 2);
	if (arg != NULL)
	{
		ft_putstr_fd(arg, 2);
		ft_putstr_fd(": ", 2);
	}
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	return (1);
}
