/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_r_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 09:54:27 by bhatches          #+#    #+#             */
/*   Updated: 2021/09/16 09:54:28 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prsng_vldtn.h"

int	double_r_fd(t_cmd_list *tmp)
{
	tmp->fd_out = open(tmp->after_redirect,
			O_CREAT | O_WRONLY | O_APPEND, S_IRWXU);
	if (tmp->fd_out < 0)
		return (NOT_EXECUTE);
	return (EXECUTE);
}
