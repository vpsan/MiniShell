/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_shell.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 16:55:52 by bhatches          #+#    #+#             */
/*   Updated: 2021/06/08 16:39:05 by bhatches         ###   ########.fr       */
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

# define ERROR -1

// // // //	MY_SHELL:
int		    my_shell(t_main *prtmtrs);

// // // // ENV:
void	    create_env_lst(t_main *prmtrs, char **env);
t_env_list	*env_lst_sort(t_env_list * c );
t_env_list	*env_lstnew(char **env_arr, int declare_flag);
void        env_lstadd_front(t_env_list **lst, t_env_list *new);
int		    env_lstsize(t_env_list *lst);
t_env_list  *env_lstlast(t_env_list *lst);
void	    env_lstadd_back(t_env_list **lst, t_env_list *new);
void	    env_lstdelone(t_env_list *lst, void *(*del)(char ***arr));
void	    env_lstclear(t_env_list **lst, void *(*del)(char ***arr));
void	    env_lstiter(t_env_list *lst, void (*f)(void *));
t_env_list	*env_lstmap(t_env_list *lst, void *(*f)(void *), void *(*del)(char ***arr));

// // // //	BUILTINS:
int         builtin_env(t_main *prmtrs);
int         builtin_unset(char *cmnd_str, char **cmnd_words, t_env_list *env_head);
int     	builtin_export(char **cmnd_words, t_env_list *env_head);
int	    	builtin_pwd(void);
int     	builtin_exit(char **cmnd_words);
int     	builtin_cd(char **cmnd_words);
int     	builtin_echo(char **cmnd_words);

// // // //	TESTERS:
// // // //	FOR ENV:
void 	    test_env_add(t_main prmtrs);
void    	test_printf_all_List_env(t_env_list *env_head);
// // // //	FOR BUILTINS:
void 	    test_builtins_env(t_main prmtrs);
void 	    test_builtins_pwd(t_main prmtrs);
void 	    test_builtins_unset(t_main prmtrs);
void 	    test_builtins_export_without_arguments(t_main prmtrs);
void 	    test_builtins_export_with_arguments(t_main prmtrs);

#endif
