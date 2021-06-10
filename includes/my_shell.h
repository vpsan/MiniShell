/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_shell.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 16:55:52 by bhatches          #+#    #+#             */
/*   Updated: 2021/06/09 22:14:05 by bhatches         ###   ########.fr       */
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
void 		env_lstsort_bubble(t_env_list *env_head);
t_env_list	*env_lstnew(char **env_arr, int declare_flag);
void        env_lstadd_front(t_env_list **lst, t_env_list *new);
int		    env_lstsize(t_env_list *lst);
t_env_list  *env_lstlast(t_env_list *lst);
void	    env_lstadd_back(t_env_list **lst, t_env_list *new);
void	    env_lstdelone(t_env_list *lst, void *(*del)(char ***arr));
void	    env_lstclear(t_env_list **lst, void *(*del)(char ***arr));
void	    env_lstiter(t_env_list *lst, void (*f)(void *));
t_env_list	*env_lstmap(t_env_list *lst, void *(*f)(void *), void *(*del)(char ***arr));
char        *getvalue_env_lst(char *name, t_env_list *env_head);
void        updatevalue_env_lst(char *name, char *malloced_new_value, t_env_list **env_head);
char 	**env_split(char const *s);

// // // //	BUILTINS:
int         builtin_env(t_main *prmtrs);
int         builtin_unset(char *cmnd_str, char **cmnd_words, t_env_list *env_head);
int     	builtin_export(char **cmnd_words, t_env_list *env_head);
int 	    print_export_declare_x(t_env_list *env_head);
int	    	builtin_pwd(void);
int     	builtin_exit(char **cmnd_words);
int     	builtin_cd(char **cmnd_words, t_env_list* env_head);
int     	builtin_echo(char **cmnd_words);

// // // //	TESTERS:
// // // //	FOR ENV:
void 	    test_env_lstsort_bubble(t_main prmtrs);
void    	test_printf_all_env_lst(t_env_list *env_head);
void 		test_updatevalue_env_lst(t_main prmtrs);
void		test_env_split(t_main prmtrs);
// // // //	FOR BUILTINS:
void 	    test_builtin_env(t_main prmtrs);
void 	    test_builtin_pwd(t_main prmtrs);
void 	    test_builtin_unset(t_main prmtrs);
void 	    test_builtin_export_without_arguments(t_main prmtrs);
void 	    test_builtin_export_with_arguments(t_main prmtrs);
void 		test_builtin_cd(t_main prmtrs);
void 		test_builtin_echo(t_main prmtrs);

#endif
