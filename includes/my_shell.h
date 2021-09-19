/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_shell.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 16:55:52 by bhatches          #+#    #+#             */
/*   Updated: 2021/09/17 01:49:31 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_SHELL_H
# define MY_SHELL_H

# include "libft.h"
# include "my_structures.h"

# include <printf.h>
# include <string.h>
# include <errno.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>

/*
**	ENV:
*/

void		create_env_lst(t_main *prmtrs, char **env);
void		env_lstsort_bubble(t_env_list *env_head);
t_env_list	*env_lstnew(char **env_arr, int declare_flag);
void		env_lstadd_front(t_env_list **lst, t_env_list *new);
int			env_lstsize(t_env_list *lst);
t_env_list	*env_lstlast(t_env_list *lst);
void		env_lstadd_back(t_env_list **lst, t_env_list *new);
void		env_lstdelone(t_env_list *lst, void *(*del)(char ***arr));
void		env_lstclear(t_env_list **lst, void *(*del)(char ***arr));
void		env_lstiter(t_env_list *lst, void (*f)(void *));
t_env_list	*env_lstmap(t_env_list *lst, void *(*f)(void *),
				void *(*del)(char ***arr));
char		*getvalue_env_lst(char *name, t_env_list *env_head);
void		updatevalue_env_lst(char *name, char *malloced_new_value,
				t_env_list **env_head);
char		**env_split(char const *s);
int			check_env_name_exists(char *name, t_env_list *env_head);
char		**env_create_arr(t_env_list *env_head);

/*
**	MAIN MY_SHELL FUNCTION:
*/

int			my_shell(t_main *prtmtrs);

/*
**	SHELL MANAGER:
*/

int			my_shell_execute(t_cmd_list *cmd_i, t_main *prmts);
int			pipe_execve_or_builtins(t_cmd_list *cmd_i, t_main *prmts);
int			redirect_cmd_fd(t_cmd_list *cmd_i);
int			create_pipe(t_cmd_list *cmd_i, t_main *prmts);

int			free_cmd_list(t_main *prmtrs, int return_value);
int			free_prmtrs(t_main *prmtrs, int return_value);

/*
**	BUILTINS:
*/

int			builtin_env(char **cmnd_words, t_env_list *env_head,
				int fd_out, t_main *prmtrs);
int			builtin_unset(char **cmnd_words, t_env_list **env_head,
				t_main *prmtrs);
void		unset_delete_lst_element(char *s, t_env_list **env_head);
int			builtin_export(char **cmnd_words, t_env_list **env_head,
				int fd_out);
int			print_export_declare_x(t_env_list *env_head, int fd_out);
int			builtin_pwd(int fd_out, t_main *prmtrs);
int			builtin_exit(char **cmnd_words, t_main *prmtrs);
int			builtin_cd(char **cmnd_words, t_env_list *env_head, t_main *prmtrs);
int			builtin_echo(char **cmnd_words, int fd_out);
int			builtins(t_cmd_list *cmd_i, t_main *prmtrs);

/*
**	EXECUTE_EXECVE:
*/

int			execute_execve(t_cmd_list *cmd_i, t_main *prmtrs);

/*
**	definition for readline:
*/

void		rl_replace_line(const char *s, int n);

#endif
