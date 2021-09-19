/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_shell.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 14:32:15 by bhatches          #+#    #+#             */
/*   Updated: 2021/09/17 01:28:37 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_shell.h"

int	my_shell(t_main *prmtrs)
{
	t_cmd_list	*cmd_i;

	cmd_i = prmtrs->cmd_head;
	prmtrs->fd_output = dup(0);
	while (cmd_i->next != NULL)
	{
		create_pipe(cmd_i, prmtrs);
		cmd_i = cmd_i->next;
	}
	my_shell_execute(cmd_i, prmtrs);
	dup2(prmtrs->fd_output, 0);
	free_prmtrs(prmtrs, DONT_CLEAN_ENV);
	while (wait(NULL) > 0)
		;
	return (0);
}
