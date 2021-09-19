/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   after_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 09:52:58 by bhatches          #+#    #+#             */
/*   Updated: 2021/09/16 09:52:59 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prsng_vldtn.h"

int	after_redirect(int j, t_cmd_list *tmp)
{
	while (tmp->orig_cmnd_str[j] && ft_isspace(tmp->orig_cmnd_str[j]))
		j++;
	if (tmp->orig_cmnd_str[j] && tmp->orig_cmnd_str[j] == '\'')
		af_quote(j, tmp);
	else if (tmp->orig_cmnd_str[j] && tmp->orig_cmnd_str[j] == '"')
		af_quotes(j, tmp);
	else
		af_alnum(j, tmp);
	return (EXECUTE);
}
