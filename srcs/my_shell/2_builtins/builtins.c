/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 17:07:23 by bhatches          #+#    #+#             */
/*   Updated: 2021/09/17 10:37:08 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_shell.h"

int	builtins(t_cmd_list *cmd_i, t_main *prmtrs)
{
	if (strcmp("cd", cmd_i->cmnd_words[0]) == 0)
		builtin_cd(cmd_i->cmnd_words, prmtrs->env_head, prmtrs);
	if (strcmp("echo", cmd_i->cmnd_words[0]) == 0)
		builtin_echo(cmd_i->cmnd_words, cmd_i->fd_out);
	if (strcmp("env", cmd_i->cmnd_words[0]) == 0)
		builtin_env(cmd_i->cmnd_words, prmtrs->env_head, cmd_i->fd_out, prmtrs);
	if (strcmp("exit", cmd_i->cmnd_words[0]) == 0)
		builtin_exit(cmd_i->cmnd_words, prmtrs);
	if (strcmp("export", cmd_i->cmnd_words[0]) == 0)
		builtin_export(cmd_i->cmnd_words, &prmtrs->env_head, cmd_i->fd_out);
	if (strcmp("pwd", cmd_i->cmnd_words[0]) == 0)
		builtin_pwd(cmd_i->fd_out, prmtrs);
	if (strcmp("unset", cmd_i->cmnd_words[0]) == 0)
		builtin_unset(cmd_i->cmnd_words, &prmtrs->env_head, prmtrs);
	return (0);
}
