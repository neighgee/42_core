/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 11:27:17 by mwin              #+#    #+#             */
/*   Updated: 2026/02/18 18:37:15 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "Libft/libft.h"
# include "pipex/main.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <signal.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <sys/stat.h>

extern volatile sig_atomic_t	g_sigint;

typedef struct s_fillc
{
	const char		*ptr;
	char			***envp;
	int				*exit_code;
	int				i;
	int				quoted;
	int				heredoc_next;
}	t_fillc;

typedef struct s_hered
{
	char			*symbol;
	char			*temp_path;
	int				expand;
	struct s_hered	*next;
}	t_hered;

typedef struct s_quote_tokenizer
{
	char		***envp;
	const char	*end;
	const char	*s;
	int			sq;
	int			dq;
	char		*result;
	int			*exit_code;
	int			expand;
}	t_quote_tokenizer;

typedef struct s_command
{
	char				**arguments;
	char				*first_arg;
	int					infd_new;
	char				*input_file; //for "<"
	int					outfd_new;
	char				*output_file; //for ">" or ">>"
	int					check_changes; //1 if ">>", 0 if ">"
	int					out_fd; //bool valid or not
	t_hered				*heredocs;	//new list of heredocs in order
	char				**hd_envp;
	int					hd_status;
	int					last_in_redrc;
	char				*stderr_file;
	int					stderr_append;
	struct s_command	*next_cmd;
}	t_command;

//built in helper
char		*ft_getenv_custom(char **envp, char *var_name);
char		***dup_envp(char **envp);
int			ft_strstr(char *inp, char *bigStr); //

//builtin
int			dw_builtin(char **args, char ***envp);
int			cd(char ***envp, char **argv);
char		*cd_2(char ***envp, char *path);
char		*free_old_ret_newpwd(char *str, char *new);
int			echo(char **args);
int			env(char **envp);
int			pwd(char **envp);
int			export(char ***envp, char **args, int fd);
int			unset(char ***envp, char **args);

//export
int			check_valid(char *var, int fd);
int			export_var_in_env(char ***envp, char *new, char *var);
int			export_var_add(char ***envp, char *new);
int			indiv_export(char ***envp, char *new);
int			export_no_arg(char ***envp, int fd);

//check_redrcs
int			store_symbols(t_command *cmd, int *exit_code);
int			skip_redrcs(t_command *cmd, char **old, char **new, int *exit_code);
int			parse_redir_symbol_fd(char **args, int *checker, int *i, int *fd);

//check_remove_quotes
char		**check_remove_quotes(const char *input_string, char ***envp,
				int *exit_code);
char		*copy_and_remove_quotes(char ***envp,
				const char *start, const char *end, int *exit_code);
char		*copy_and_remove_quotes_noexp(char ***envp,
				const char *start, const char *end, int *exit_code);

//env_var.c
int			edge_case_expansion(const char *cmd, char **result, char **envp,
				int *i);
int			append_exit_code(t_quote_tokenizer *s);

//input_checker
int			bad_path(char **args);
int			check_input(char **input_string, char ***envp,
				int *exit_code, int *can_ex);
void		real_sep_with_null(char *s, int str_len, char sep);
char		**split_on_null(char *s, int str_len);

//execute_cmd , 2
int			execute_cmds(char **pipes, char ***envp, int *exit_code,
				int *can_ex);
int			no_pipes(t_command *curr, char ***envp);
int			is_builtin(char *cmd);
int			exit_status_only(char **cmds);
int			exit_help(int last_pid);
int			create_pipeline(t_command *curr, char ***envp);
int			child_fn(int prev_fd, t_command *curr, int p[2], char ***envp);
t_command	*parent_fn(int *prev_fd, t_command *curr, int p[2]);

//parser_utils
int			check_whitespace(char *s);
void		restore_ctrls(char *s);
void		free_arr(char **cmds);
void		free_list(t_command *cmd);
char		*ft_strjoin_char(char *string, char c);
char		*substr_len(const char *s, int start, int len);
int			which_redir(t_command *cmd, int symbol, int fd);

//handle_quotes
const char	*skip_quotes(const char *s, int *quoted);
int			count_cmds(const char *string, int *quoted);
int			handle_quotes_and_others(t_quote_tokenizer *s);
int			is_space(char c);
char		*append_char(char *result, char c);

//redrc_sym_utils
int			handle_output_redrc(t_command *cmd, char *target,
				int append, int fd);
int			redir_skip(const char *token, int symbol);
int			ambig_redrc(const char *target);
int			redrc_last(const char *s);

//store_cmd_list
t_command	*store_cmds(char **pipes, char ***envp, int *exit_code);

//syntax_utils.c
void		unexpected_msg(char c);
int			wrong_target(char *token);
int			check_append_heredoc(char *token, int *checker);
int			heredoc_inputs(t_command *cmd, int symbol, char *target);
char		*redir_target(char **args, int i, int symbol, int *skip);
int			close_fds(int status, int dummy_in, int dummy_out, int dummy_err);

//input_redrcs
int			exec_input_redrc(t_command *cmd, int *stdin_file, int *in_fd);
int			append_hd(t_command *cmd, char *token);
void		restore_fd(int org_fd, int target_fd);
int			save_fd(int target_fd, int *org);
int			redirect_fd(int opened_fd, int target_fd);

//output_redrcs
int			exec_output_redrc(t_command *cmd, int *org_out, int *org_err,
				int org_in);

//redrc_utils
void		restore_redrcs(int stdin_file, int stdout_file);
int			handle_redrcs(t_command *cmd, int *org_in, int *org_out,
				int *org_err);
void		heredoc_child(t_hered *heredoc, int fd, char ***envp,
				t_command *head);
void		bad_symbol(int *checker, char *token);

//exit_cmds
int			code(char *code);
int			exit_entry(char **cmds, int *exit_code, int *can_ex);
void		exit_cmd(char ***envp, int status, t_command *cmd);
int			str_is_num(const char *s);

//signals
int			ctrl_d(char *input_string);
void		ctrl_c(int signal);
void		initialise_signals(void);
void		initialise_child_signals(void);
void		initialise_exec_signals(void);
void		heredoc_sigint(int signal);

//kinda like libft
int			ft_arrlen(char **arr);
int			is_builtin(char *cmd);
int			exit_status_only(char **cmds);
int			exit_help(int last_pid);
int			pipe_syntax(const char *s);
int			is_space(char c);

//Heredoc utils
int			open_hds(char **out_path);
t_hered		*last_hd(t_hered *heredoc);
int			many_hd(t_command *cmds, char ***envp);
void		free_hd(t_hered *heredoc);
int			is_redir(char c);
void		close_fd_child(int fd);
void		hd_exit(int code, t_command *head, char ***envp);
int			hd_delim(char *input, char *symbol, size_t sym_len);
int			empty_tok(char *s);
void		hd_freeline(char *input, char *line);
int			hd_loop(t_hered *heredoc, int fd, char ***envp, int status);

//dealwith_space
char		*add_spc_redrc(const char *s);

//minishell.c
void		free_dupenvp(char ***dupenvp);

void		close_extra_fds(void);
void		close_once(int *fd);
void		close_stdfd(void);
void		hd_write(int fd, char *input);
char		*hd_quoted(char *s, int quoted);
int			handle_dollar(t_quote_tokenizer *s);
char		*hd_expand(const char *src, char ***envp, int status);

char		*copy_cmds_expand(const char **string, char ***envp,
				int *exit_code, int *quoted);
int			is_hd(char *s);
char		*copy_hd_target(const char **ptr, char ***envp,
				int *exit_code, int *quoted);
int			is_hd(char *s);
void		skip_spc(t_fillc *fc);
int			copy_one_token(t_fillc *fc, char **cmds);
void		eat_tok(t_fillc *fc, char **cmds);
void		drop_tok(t_fillc *c, char **cmds);

#endif
