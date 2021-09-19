/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 12:01:53 by bhatches          #+#    #+#             */
/*   Updated: 2021/09/17 01:27:43 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_shell.h"

void	ft_cmd_list_del(t_cmd_list *cmd_i, int (*del_str)(char **str),
											void *(*del_arr)(char ***arr))
{
	if ((*del_str) != NULL && (*del_arr) != NULL)
	{
		(*del_str)(&cmd_i->orig_cmnd_str);
		(*del_str)(&cmd_i->copy_cmnd_str);
		(*del_arr)(&cmd_i->cmnd_words);
		(*del_str)(&cmd_i->before_redirect);
		(*del_str)(&cmd_i->after_redirect);
	}
	if (cmd_i != NULL)
		free(cmd_i);
	return ;
}

void	ft_cmd_list_clear(t_cmd_list **cmd_head, int (*del_str)(char **str),
												void *(*del_arr)(char ***arr))
{
	if (*cmd_head && cmd_head)
	{
		ft_cmd_list_clear(&(*cmd_head)->next, del_str, del_arr);
		ft_cmd_list_del(*cmd_head, del_str, del_arr);
		*cmd_head = NULL;
	}
	return ;
}

int	free_cmd_list(t_main *prmtrs, int return_value)
{
	ft_cmd_list_clear(&prmtrs->cmd_head, ft_free_str, ft_free_str_arr);
	return (return_value);
}

int	free_prmtrs(t_main *prmtrs, int return_value)
{
	ft_free_str(&(prmtrs->orig_line_input));
	ft_free_str(&(prmtrs->copy_line_input));
	free_cmd_list(prmtrs, return_value);
	if (return_value == ERROR || return_value == SUCCESSFUL_EXIT)
		env_lstclear(&(prmtrs->env_head), ft_free_str_arr);
	return (return_value);
}
