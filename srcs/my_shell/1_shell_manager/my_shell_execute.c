/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_shell_execute.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 11:15:49 by bhatches          #+#    #+#             */
/*   Updated: 2021/09/16 23:04:35 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_shell.h"

int	my_shell_execute(t_cmd_list *cmd_i, t_main *prmts)
{
	if (cmd_i->is_builtin == true)
	{
		builtins(cmd_i, prmts);
	}
	else
	{
		pipe_execve_or_builtins(cmd_i, prmts);
	}
	return (0);
}
