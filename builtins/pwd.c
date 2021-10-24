/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abambi <abambi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 07:19:51 by brattles          #+#    #+#             */
/*   Updated: 2021/10/17 17:19:20 by abambi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(void)
{
	char	*pwd;

	pwd = NULL;
	pwd = getcwd(pwd, PATH_MAX);
	write(1, pwd, ft_strlen(pwd));
	write(1, "\n", 1);
	free(pwd);
	return (0);
}
