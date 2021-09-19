/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   al_num.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 09:53:01 by bhatches          #+#    #+#             */
/*   Updated: 2021/09/16 09:53:02 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prsng_vldtn.h"

int	al_num(t_cmd_list **tmp, int i, int ind)
{
	int	j;

	j = -1;
	find_builtin((*tmp), i);
	while ((*tmp)->orig_cmnd_str[i] && !ft_isspace((*tmp)->orig_cmnd_str[i]))
		(*tmp)->cmnd_words[ind][++j] = (*tmp)->orig_cmnd_str[i++];
	return (i);
}
