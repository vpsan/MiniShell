/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 15:40:13 by bhatches          #+#    #+#             */
/*   Updated: 2021/09/17 01:28:12 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_shell.h"

int	print_errno_env(char *str, t_main *prmtrs, int rtrn_value)
{
	ft_putstr_fd("env: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(strerror(errno), 2);
	prmtrs->exit_status = 1;
	return (rtrn_value);
}

int	builtin_env(char **cmnd_words, t_env_list *env_head, int fd_out,
															t_main *prmtrs)
{
	t_env_list	*tmp;

	if (cmnd_words[1] != NULL)
		return (print_errno_env(cmnd_words[1], prmtrs, ERROR));
	tmp = env_head;
	while (tmp != NULL)
	{
		if (tmp->declare_flag != 0)
		{
			ft_putstr_fd(tmp->env_arr[0], fd_out);
			ft_putstr_fd("=", fd_out);
			ft_putstr_fd(tmp->env_arr[1], fd_out);
			ft_putstr_fd("\n", fd_out);
		}
		tmp = tmp->next;
	}
	return (0);
}
