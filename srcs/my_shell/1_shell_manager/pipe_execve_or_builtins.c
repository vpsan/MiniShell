/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_execve_or_builtins.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 11:18:24 by bhatches          #+#    #+#             */
/*   Updated: 2021/09/16 23:04:40 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_shell.h"

int	pipe_execve_or_builtins(t_cmd_list *cmd_i, t_main *prmts)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		exit(free_prmtrs(prmts, ERROR));
	}
	else if (pid == 0)
	{
		redirect_cmd_fd(cmd_i);
		execute_execve(cmd_i, prmts);
		free_prmtrs(prmts, 0);
	}
	else
	{
		waitpid(pid, &(prmts->exit_status), 0);
		prmts->exit_status = WEXITSTATUS(prmts->exit_status);
	}
	return (0);
}
