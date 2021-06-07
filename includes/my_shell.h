/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_shell.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 16:55:52 by bhatches          #+#    #+#             */
/*   Updated: 2021/06/07 17:06:45 by bhatches         ###   ########.fr       */
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

//	MY_SHELL:
int		my_shell(t_main *prtmtrs);

//	BUILTINS:
int		pwd(void);
int     ft_env(t_main *prmtrs);

// ENV:
void	create_env_var(t_main *prmtrs, char **env);
void	ft_lst_test_printf(t_list *env_head);
t_list	*ft_lst_Sort(t_list * c );

#endif
