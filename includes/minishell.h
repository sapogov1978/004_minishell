/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 00:18:59 by brattles          #+#    #+#             */
/*   Updated: 2021/06/30 01:20:59 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <string.h>
# include <sys/wait.h>
# include <stddef.h>
# include <readline/readline.h>
# include <readline/history.h>

# define PATH_MAX	4096
# define REWRITE	1
# define APPEND		2
# define READ_FROM	3
# define HEREDOC	4

# define PIPE		1
# define COMMAND	0

# define STDIN		0
# define STDOUT		1
# define STDERR		2

# define READ		0
# define WRITE		1

extern int			g_last_code;

typedef struct s_letters
{
	char				character;
	struct s_letters	*next;
}	t_letters;

typedef struct s_wordlists
{
	char				*str;
	struct s_wordlists	*next;
}	t_wordlists;

typedef struct s_redirect
{
	char				*one_param;
	int					redir_type;
	struct s_redirect	*next;
}						t_redirect;

typedef struct s_cmds
{
	char				**arr_params;
	int					flag;
	t_redirect			*redirect;
	struct s_cmds		*next;
}						t_cmds;

typedef struct s_vars
{
	char				**envir;
	char				*buff;
	char				*username;
	t_cmds				*cmds;
	t_redirect			*redir;
	t_wordlists			*words;
	t_letters			*one_word;
	char				**arr_cmds_ptr;
	char				**pipes_arr_ptr;
}						t_vars;

void		add_slashes(t_vars *vars, int count, char c);
void		add_to_letters(t_vars *vars, char c);
void		add_to_wordlist(t_wordlists **head, t_letters **abc, t_vars *vars);
int			analyze_exit_arg(t_vars *vars);

void		check_n_args(int ac);
int			check_pipes(t_redirect *command);
void		check_split_errors(char *s, char c);
void		check_start_errors(char *s);
void		cmd_addback(t_cmds **lst, t_cmds *new);
char		*compose_envvar(char *name, char *value);
char		**convert_to_char_zz(t_wordlists **head, t_vars *vars);
char		**copy_environ(char **envp, t_vars *vars);
int			count_chars(char *s, char c);

int			do_each_cmd(t_vars *vars);

int			env_strcmp(char *name, char *env_var);
void		execute(char **argv, t_vars *vars);
int			exec_composed_path(t_vars *vars, char **exe, char *path);
int			exec_environ_path(t_vars *vars, char **exe);
int			execution(t_vars *vars);
int			export_values(char *str, t_vars *vars);

char		*find_env_var(char *name, char *envp[]);
int			fork_dup(t_vars *vars);
char		*found_env_path(char **envp);
int			found_pipe(char *s);
void		free_cmds(t_cmds **cmds);
void		free_letters(t_letters **one_word);
void		free_redirects(t_redirect **redir);
int			free_strsplit(char **all_path);
void		free_wordlists(t_wordlists **words);
int			ft_b_err(char *bash, char *cmd, char *arg, char *msg);
int			ft_cd(char **arr_params, t_vars *vars);
int			ft_echo(char **arr_params);
char		ft_detect_char(char *str);
int			ft_exit_program(t_vars *vars);
int			ft_export(char *str, t_vars *vars);
int			ft_heredoc(char *str, t_vars *vars);
void		ft_panic(t_vars *vars, char *msg, int return_code);
int			ft_print_env(char **argv, t_vars *vars, char *prefix);
int			ft_pwd(void);
char		ft_smart_detect_char(char *str, int i);
char		**ft_split_ms(char *arr, char c);
int			ft_unset(char *str, t_vars *vars);

t_cmds		*get_each_cmd(t_vars *vars, char *arr_cmds);
void		get_env_data(t_vars *vars, char **envp);
char		*get_name(char *str);
void		get_next_line_ms(t_vars *vars);
char		**get_params(char *cmd_params, t_vars *vars);
t_wordlists	*get_redir_params(char **cmd_params, t_vars *vars);
char		*get_value(char *str);
int			go_through_redirs(char **str, t_vars *vars);

void		handler_sigint(int sig);
void		handler_sigquit(int sig);

void		init_struct(t_vars *vars);
char		**insert_envvar(t_vars *vars, char *name, \
				char *value, char **envp);
int			is_pipe_at_end(char *str, t_cmds *cmd_chain);
int			is_spec_symbol(char *s);
void		isolate_cmd(t_redirect *redir, char **str, t_vars *vars);
void		isolate_cmd_params(t_vars *vars, char *arr, int flag);
t_cmds		*isolate_one_cmd(t_cmds **lst, t_redirect **redir, \
				char **str, int i);
char		*isolate_var_name(t_vars *vars, char *str, int len);

int			launch_other_cmds(char **argv, t_vars *vars);
void		letter_addback(t_letters **lst, t_letters *new);
int			letters_size(t_letters *str);
char		*letters_to_word(t_letters **str, t_vars *vars);

char		*main_parsing(char *str, t_vars *vars);

int			num_lines(char **argv);

char		*parse_dollar_other(t_vars *vars, char *s);
char		*parse_dollar_what(t_vars *vars, char *s);
void		parse_double_quotes(t_vars *vars, char **s);
char		*parse_home_path(t_vars *vars, char *str);
char		*parse_just_slashes(char *s, int i, t_vars *vars);
char		*parse_shielded_duoquote(char *s, int i, t_vars *vars);
char		*parse_simple_quote_inside_duoquotes(char *s, \
				int i, t_vars *vars);
void		parse_simple_quotes(t_vars *vars, char **s);
char		*parse_slash(t_vars *vars, char *s, int flag);
void		parse_str(t_vars *vars);
void		pipe_branch(t_vars *vars, char *arr_cmds);

int			read_from(t_redirect *redir, t_vars *vars);
void		redir_addback(t_redirect **lst, t_redirect *new);
int			redirection(t_vars *vars);
int			rewrite_envvar(char *name, char *value, char **envp);

void		set_collected_info(t_vars *vars, int redir_type);
void		set_heredoc(t_vars *vars);
t_cmds		*set_params(char **cmd_params, int flag, \
				t_redirect *redir, t_vars *vars);
void		set_pipe_flag(t_cmds *lst);
void		set_redir_params(t_vars *vars, t_letters **abc, int flag);
void		shell_prompt_msg(t_vars *vars);
void		skip_spaces(char **str);
int			start_cmd(t_vars *vars, int fd_in);
int			start_processes(int id, int fd_buf[2], t_vars *vars);
int			start_program(t_vars *vars);
int			syntax_error(int flag);

void		wordlist_add_back(t_wordlists **lst, t_wordlists *new);
int			wordlists_size(t_wordlists *wordlists);
int			write_to(t_redirect *redir, t_vars *vars);

#endif
