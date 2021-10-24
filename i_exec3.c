/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_exec3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 07:07:35 by brattles          #+#    #+#             */
/*   Updated: 2021/10/19 00:08:37 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	launch_other_cmds(char **arr_params, t_vars *vars)
{
	int		status;
	pid_t	id;

	status = 0;
	id = fork();
	if (id < 0)
		ft_panic(vars, "Error in fork\n", 1);
	else if (id == 0)
		execute(arr_params, vars);
	else
	{
		signal(SIGQUIT, handler_sigquit);
		signal(SIGINT, handler_sigint);
		waitpid(id, &status, WUNTRACED);
	}
	if (WIFSIGNALED(status) != 0)
	{
		if (WTERMSIG(status) == 2)
			return (130);
		else if (WTERMSIG(status) == 3)
			return (131);
	}
	return (WEXITSTATUS(status));
}

void	execute(char **arr_params, t_vars *vars)
{
	int	res;

	if (arr_params[0][0] == '/')
		res = execve(arr_params[0], &arr_params[0], vars->envir);
	else if (arr_params[0][0] == '.' && arr_params[0][1] == '/')
		res = exec_composed_path(vars, arr_params, NULL);
	else
		res = exec_environ_path(vars, arr_params);
	if (res == -1)
	{
		ft_b_err("", 0x0, arr_params[0], "command not found");
		ft_panic(vars, "", 127);
	}
}

int	exec_composed_path(t_vars *vars, char **exe, char *path)
{
	char	*full_cmd;
	char	*path_env;

	path_env = NULL;
	if (path != NULL)
		full_cmd = ft_strjoin(path, "/");
	else
	{
		path_env = getcwd(path_env, 0);
		if (path_env == NULL)
			ft_panic(vars, "Error in execute 1\n", 1);
		full_cmd = ft_strjoin(path_env, "/");
		free(path_env);
	}
	if (full_cmd == NULL)
		ft_panic(vars, "Error in malloc for execute 1\n", 1);
	full_cmd = ft_strjoinf(&full_cmd, *exe);
	if (full_cmd == NULL)
		ft_panic(vars, "Error in malloc for execute 2\n", 1);
	return (execve(full_cmd, exe, vars->envir));
}

int	exec_environ_path(t_vars *vars, char **exe)
{
	char	*env_path;
	char	**all_paths;
	int		i;

	env_path = found_env_path(vars->envir);
	if (env_path == NULL)
		return (-1);
	all_paths = ft_split(&env_path[5], ':');
	if (all_paths == NULL)
		ft_panic(vars, "Error:\n->malloc error for environ paths\n", 1);
	i = -1;
	while (all_paths[++i])
		if (exec_composed_path(vars, exe, all_paths[i]) != -1)
			return (1);
	free_strsplit(all_paths);
	return (-1);
}

char	*found_env_path(char **envp)
{
	int	i;

	i = -1;
	while (envp[++i])
		if ((ft_strncmp("PATH=", envp[i], 5)) == 0)
			return (envp[i]);
	return (NULL);
}
