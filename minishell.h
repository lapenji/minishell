/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltombell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:45:27 by aboncine          #+#    #+#             */
/*   Updated: 2023/02/09 13:10:54 by ltombell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "get_next_line.h"

typedef struct s_cmd	t_cmd;

typedef struct s_prg
{
	t_cmd	*cmds;
	char	**envp_copy;
	pid_t	pid;
}		t_prg;

typedef struct s_cmd
{
	char	**full_cmd;
	int		infile;
	int		outfile;
	char	*delimiter;
	t_cmd	*next;
}		t_cmd;

extern int				g_exitstatus;

char	**ft_split(char const *s, char c);
char	**get_paths(char **envp);
void	execute_cmd(char **cmd_args, char **envp);
char	*ft_strtrim(char *s1, char *set);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	variable_expander(char **prompt);
char	*ft_strdup(const char *s);
char	**ft_simple_split(char const *s, char c);
char	*ft_extract_var(char *s);
char	**parse_pipe_min_mag(char **prompt);
char	*ft_strncpy(char *s, int start, int finish);
int		is_there_a_special_char(char *s);
void	ft_add_element(t_cmd **cmd_list, char **cmd_arr);
void	ft_clean_list(t_cmd *comandi);
void	ft_simple_echo(char **to_print, int n);
char	*ft_create_sc_word(char *s, int start, int i);
int		how_many_strings(char **prompt);
int		how_many_strings_with_s_c(char *s);
int		how_many_special_chars(char *s);
char	*create_str3(char const *s, int *i, int *flag, char *c);
void	here_doc_handler(char *delim);
void	ft_check_for_minus(t_cmd *elem);
char	*ft_itoa(int n);
char	**ft_dup_arr(char **arr);
char	**ft_add_string_to_arr(char **arr, char *s);
char	**ft_remove_string_from_arr(char **arr, int toremove);
void	ft_print_env_b(void);
char	**ft_altro_split(char *s);
int		ft_is_var_inside_quotes(char *s);
char	*ft_gestisci_virgo(char *str);
int		ft_is_valid_var_name(char *s);
void	ft_export_var(char *prompt);
void	ft_print_export(void);
void	ft_free_strarr(char **strarr);
int		ft_is_there_virgos(char *str);
void	ft_the_executer(t_prg *box, char **envp);
int		ft_is_good_exit_status(char *s);
char	*ft_remove_virgo_exit_status(char *s);
void	free_n_exit(char *res);
void	ft_unset_var(char *str);
void	ft_signal_ctrl_c(int sig);
void	ft_signal_ctrl_bs(int sig);
void	ft_others(char **cmd_args, t_prg box, char **envp);
void	ft_exit(char **cmd_args, t_prg box);
int		ft_is_there_a_pipe(char *s);
void	ft_check_if_trimmable(char *s1, size_t *first, size_t *last);
char	*ft_extact_var_free(char *dopo, char *tmp2, char *res, char *s);
char	*ft_ft_extract_var_getenv(char *res, int *flag);
int		ft_atoi(const char *nptr);
void	ft_cd(char **cmd_args);
void	ft_print_header(void);

#endif
