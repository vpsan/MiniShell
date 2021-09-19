/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   before_redirect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 11:03:59 by bhatches          #+#    #+#             */
/*   Updated: 2021/09/17 11:04:52 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prsng_vldtn.h"

int	before_redirect(int *j, t_cmd_list *tmp)
{
	while ((!ft_isalnum(tmp->orig_cmnd_str[(*j)])
			&& tmp->orig_cmnd_str[(*j)] != '\''
			&& tmp->orig_cmnd_str[(*j)] != '"'))
		(*j) -= 1;
	if (tmp->orig_cmnd_str[(*j)] && tmp->orig_cmnd_str[(*j)] == '\'')
	{
		if (be_quote(j, tmp) == BREAK)
			return (BREAK);
		return (CONTINUE);
	}
	if (tmp->orig_cmnd_str[(*j)] && tmp->orig_cmnd_str[(*j)] == '"')
	{
		if (be_quotes(j, tmp) == BREAK)
			return (BREAK);
		return (CONTINUE);
	}
	if (ft_isalnum(tmp->orig_cmnd_str[(*j)]))
	{
		if (be_alnum(j, tmp) == BREAK)
			return (BREAK);
		return (CONTINUE);
	}
	return (EXECUTE);
}
