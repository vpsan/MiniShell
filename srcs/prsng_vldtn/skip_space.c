/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_space.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 09:55:50 by bhatches          #+#    #+#             */
/*   Updated: 2021/09/16 09:55:51 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prsng_vldtn.h"

int	skip_space(t_cmd_list **tmp, int i)
{
	while ((*tmp)->orig_cmnd_str[i] && ft_isspace((*tmp)->orig_cmnd_str[i]))
		i++;
	return (i);
}
