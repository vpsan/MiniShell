/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 09:55:34 by bhatches          #+#    #+#             */
/*   Updated: 2021/09/16 09:55:35 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prsng_vldtn.h"

int	serch(t_cmd_list **tmp, int *i, int ind, t_main *prmtrs)
{
	int	flag;

	flag = 0;
	(*i) = skip_space(tmp, (*i));
	if ((*tmp)->orig_cmnd_str[(*i)] == '\'')
	{
		(*i) = quote(tmp, (*i), ind);
		flag = -2;
	}
	else if ((*tmp)->orig_cmnd_str[(*i)] == '"')
	{
		(*i) = quotes(tmp, (*i), ind, prmtrs);
		flag = -2;
	}
	else if (ft_isascii((*tmp)->orig_cmnd_str[(*i)])
		&& (*tmp)->orig_cmnd_str[(*i)] != '<'
		&& (*tmp)->orig_cmnd_str[(*i)] != '>'
		&& (*tmp)->orig_cmnd_str[(*i)] != '$')
	{
		(*i) = al_num(tmp, (*i), ind);
		flag = -2;
	}
	return (flag);
}
