/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_shell.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 16:55:52 by bhatches          #+#    #+#             */
/*   Updated: 2021/05/31 15:28:49 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_SHELL_H
# define MY_SHELL_H

# include "libft.h"
# include "my_structures.h"

# include <string.h>
# include <errno.h>

# define ERROR -1

int		my_shell(t_shell *prtmtrs);
int		pwd(void);
int		echo(char *c_arg, int fd);

#endif
