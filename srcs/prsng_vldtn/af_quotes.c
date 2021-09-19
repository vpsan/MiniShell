/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   af_quotes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 09:52:55 by bhatches          #+#    #+#             */
/*   Updated: 2021/09/16 09:52:56 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prsng_vldtn.h"

void	af_quotes(int j, t_cmd_list *tmp)
{
	int		len;
	char	*ex;

	len = 0;
	j += 1;
	while (tmp->orig_cmnd_str[j] && tmp->orig_cmnd_str[j] != '"')
	{
		len += 1;
		j++;
	}
	if (tmp->after_redirect != NULL)
	{
		ex = ft_strdup(tmp->after_redirect);
		ft_free_str(&(tmp->after_redirect));
		tmp->after_redirect = ft_substr(tmp->orig_cmnd_str, (j - len), j);
		ft_free_str(&ex);
	}
	else
		tmp->after_redirect = ft_substr(tmp->orig_cmnd_str, (j - len), j);
}
