/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_redirect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 09:54:37 by bhatches          #+#    #+#             */
/*   Updated: 2021/09/16 09:54:38 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prsng_vldtn.h"

int	right_redir(t_cmd_list *tmp, int *i)
{
	if (tmp->orig_cmnd_str[(*i) + 1] == '>')
	{
		tmp->is_double_r = true;
		double_r_redirect(tmp, (*i));
		if (double_r_fd(tmp) == NOT_EXECUTE)
			return (-1);
		(*i) += 2;
	}
	else
	{
		tmp->is_single_r = true;
		single_r_redirect(tmp, (*i));
		if (single_r_fd(tmp) == NOT_EXECUTE)
			return (-1);
		(*i) += 1;
	}
	return (EXECUTE);
}

int	left_redir(t_cmd_list *tmp, int *i)
{
	if (tmp->orig_cmnd_str[(*i) + 1] == '<')
	{
		tmp->is_double_r = true;
		double_l_redirect(tmp, (*i));
		if (double_l_fd(tmp) == NOT_EXECUTE)
			return (-1);
		(*i) += 2;
	}
	else
	{
		tmp->is_single_r = true;
		single_l_redirect(tmp, (*i));
		if (single_l_fd(tmp) == NOT_EXECUTE)
			return (-1);
		(*i) += 1;
	}
	return (EXECUTE);
}

int	find_redirect(t_cmd_list *tmp, int i)
{
	if (tmp->orig_cmnd_str[i] == '>')
	{
		if (right_redir(tmp, &i) == -1)
			return (-1);
	}
	else if (tmp->orig_cmnd_str[i] == '<')
		if (left_redir(tmp, &i) == -1)
			return (-1);
	return (i);
}
