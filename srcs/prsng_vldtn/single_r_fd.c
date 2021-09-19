/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_r_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 09:55:46 by bhatches          #+#    #+#             */
/*   Updated: 2021/09/16 09:55:47 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prsng_vldtn.h"

int	single_r_fd(t_cmd_list *tmp)
{
	tmp->fd_out = open(tmp->after_redirect, O_CREAT
			| O_WRONLY | O_TRUNC, S_IRWXU);
	if (tmp->fd_out < 0)
		return (NOT_EXECUTE);
	return (EXECUTE);
}
