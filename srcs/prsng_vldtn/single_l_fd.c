/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_l_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 09:55:41 by bhatches          #+#    #+#             */
/*   Updated: 2021/09/16 09:55:42 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prsng_vldtn.h"

int	single_l_fd(t_cmd_list *tmp)
{
	tmp->fd_in = open(tmp->after_redirect, O_RDONLY);
	if (tmp->fd_in < 0)
		return (NOT_EXECUTE);
	return (EXECUTE);
}
