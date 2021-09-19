/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 09:55:26 by bhatches          #+#    #+#             */
/*   Updated: 2021/09/16 09:55:27 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prsng_vldtn.h"

int	quote(t_cmd_list **tmp, int i, int ind)
{
	int	j;

	j = -1;
	i += 1;
	while ((*tmp)->orig_cmnd_str[i] != '\'')
		(*tmp)->cmnd_words[ind][++j] = (*tmp)->orig_cmnd_str[i++];
	i += 1;
	return (i);
}
