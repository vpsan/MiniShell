/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_r_redirect.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 09:54:29 by bhatches          #+#    #+#             */
/*   Updated: 2021/09/16 09:54:30 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prsng_vldtn.h"

int	double_r_redirect(t_cmd_list *tmp, int i)
{
	int	j;

	j = i - 1;
	while (tmp->orig_cmnd_str[j])
		if (before_redirect(&j, tmp) == BREAK)
			break ;
	j = i + 2;
	after_redirect(j, tmp);
	return (EXECUTE);
}
