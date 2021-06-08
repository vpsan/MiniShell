/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_shell.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 16:55:52 by bhatches          #+#    #+#             */
/*   Updated: 2021/06/08 15:06:28 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_SHELL_H
# define MY_SHELL_H

# include "libft.h"
# include "my_structures.h"

# include <printf.h>
# include <string.h>
# include <errno.h>

# define ERROR -1
# define FALSE 0
# define TRUE 1

//	MY_SHELL:
int		my_shell(t_main *prtmtrs);

// ENV:
void	create_env_var(t_main *prmtrs, char **env);
t_list	*ft_lst_Sort(t_list * c );

//	BUILTINS:
int     builtin_env(t_main *prmtrs);
int     builtin_unset(char *cmnd_str, char **cmnd_words, t_list *env_head);
int 	builtin_export(char **cmnd_words, t_list *env_head);
int		builtin_pwd(void);
int 	builtin_exit(char **cmnd_words);
int 	builtin_cd(char **cmnd_words);
int 	builtin_echo(char **cmnd_words);

///	TESTERS:
//	FOR ENV:
void 	test_env_add(t_main prmtrs);
void	test_printf_all_List_env(t_list *env_head);
//	FOR BUILTINS:
void 	test_builtins_env(t_main prmtrs);
void 	test_builtins_pwd(t_main prmtrs);
void 	test_builtins_unset(t_main prmtrs);
void 	test_builtins_export_without_arguments(t_main prmtrs);
void 	test_builtins_export_with_arguments(t_main prmtrs);

#endif
