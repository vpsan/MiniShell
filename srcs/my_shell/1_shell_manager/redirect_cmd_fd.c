/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_cmd_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 11:19:03 by bhatches          #+#    #+#             */
/*   Updated: 2021/09/06 20:55:51 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_shell.h"

int	redirect_cmd_fd(t_cmd_list *cmd_i)
{
	if (cmd_i->is_double_l == true || cmd_i->is_single_l == true)
	{
		dup2(cmd_i->fd_in, 0);
		close(cmd_i->fd_in);
	}
	else if (cmd_i->is_double_r == true || cmd_i->is_single_r == true)
	{
		dup2(cmd_i->fd_out, 1);
		close(cmd_i->fd_out);
	}
	else
	{
		dup2(cmd_i->fd_out, 1);
		dup2(cmd_i->fd_in, 0);
	}
	return (0);
}
