/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 11:21:28 by bhatches          #+#    #+#             */
/*   Updated: 2021/09/16 22:42:58 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_shell.h"

int	create_pipe(t_cmd_list *cmd_i, t_main *prmts)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd))
		exit(free_prmtrs(prmts, ERROR));
	pid = fork();
	if (pid == -1)
		exit(free_prmtrs(prmts, ERROR));
	else if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		my_shell_execute(cmd_i, prmts);
		close(fd[1]);
		exit(1);
	}
	else
	{
		dup2(fd[0], 0);
		close(fd[0]);
		close(fd[1]);
	}
	return (0);
}
