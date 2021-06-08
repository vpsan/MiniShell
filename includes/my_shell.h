/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_shell.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 16:55:52 by bhatches          #+#    #+#             */
/*   Updated: 2021/06/07 18:30:21 by bhatches         ###   ########.fr       */
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

//	BUILTINS:
int		pwd(void);
int     env(t_main *prmtrs);
int     unset(char *cmnd_str, char **cmnd_words, t_list *env_head);
int 	export(char **cmnd_words, t_list *env_head);

// ENV:
void	create_env_var(t_main *prmtrs, char **env);
t_list	*ft_lst_Sort(t_list * c );

// TESTERS:
void 	test_env_add(t_main prmtrs);
void	test_printf_all_List_env(t_list *env_head);

void 	test_builtins_env(t_main prmtrs);
void 	test_builtins_pwd(t_main prmtrs);
void 	test_builtins_unset(t_main prmtrs);
void 	test_builtins_export_without_arguments(t_main prmtrs);
void 	test_builtins_export_with_arguments(t_main prmtrs);


#endif
