/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_heredoc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 22:45:26 by brattles          #+#    #+#             */
/*   Updated: 2021/10/20 00:13:01 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_next_line(char **line, t_vars *vars)
{
	char	d[2];
	int		len;

	len = 0;
	if (line == NULL)
		return (-1);
	*line = malloc(1 * sizeof(char));
	if (*line == NULL)
		ft_panic(vars, "malloc error", 1);
	**line = '\0';
	while (1)
	{
		len = read(0, d, 1);
		if (len != 1 || d[0] == '\n')
			break ;
		d[1] = '\0';
		*line = ft_strjoinf(line, d);
		if (*line == NULL)
			ft_panic(vars, "malloc error", 1);
	}
	return (len);
}

int	ft_heredoc(char *s, t_vars *vars)
{
	char		*line;
	int			reader;
	char		*new;

	reader = get_next_line(&line, vars);
	if (!ft_strncmp(line, s, ft_strlen(s)))
	{
		free(line);
		return (0);
	}
	new = ft_strdup(line);
	while (reader)
	{
		reader = get_next_line(&line, vars);
		if (!ft_strncmp(line, s, ft_strlen(s)))
			break ;
		new = ft_strjoinf(&new, "\n");
		new = ft_strjoinf(&new, line);
	}
	free(line);
	ft_putstr_fd(new, 1);
	free(new);
	write(1, "\n", 1);
	return (0);
}
