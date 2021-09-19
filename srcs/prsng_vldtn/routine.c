/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 09:55:31 by bhatches          #+#    #+#             */
/*   Updated: 2021/09/16 09:55:32 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prsng_vldtn.h"

int	routine(t_cmd_list **tmp, int *i, int ind, t_main *prmtrs)
{
	if (serch(tmp, i, ind, prmtrs) == -2)
		return ((*i));
	else if ((*tmp)->orig_cmnd_str[(*i)] == '$')
	{
		(*i) = dollar(tmp, (*i), ind, prmtrs);
		if ((*i) == CONTINUE)
			return (CONTINUE);
	}
	else if ((*tmp)->orig_cmnd_str[(*i)] == '>'
		|| (*tmp)->orig_cmnd_str[(*i)] == '<')
	{
		(*i) = find_redirect((*tmp), (*i));
		if ((*i) == -1)
			return (NOT_EXECUTE);
		if (serch(tmp, i, ind, prmtrs) == -2)
			return ((*i));
	}
	return ((*i));
}
