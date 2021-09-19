/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   be_quotes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 09:53:08 by bhatches          #+#    #+#             */
/*   Updated: 2021/09/16 09:53:09 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prsng_vldtn.h"

int	be_quotes(int *j, t_cmd_list *tmp)
{
	int		len;
	char	*str;

	len = 0;
	while (tmp->orig_cmnd_str[(*j) - 1]
		   && tmp->orig_cmnd_str[(*j) - 1] != '"')
	{
		(*j)--;
		len += 1;
	}
	len += 1;
	str = ft_substr(tmp->orig_cmnd_str, (*j), len);
	if (find_builtin(tmp, (*j)) == 1)
	{
		ft_free_str(&str);
		return (BREAK);
	}
	else
	{
		tmp->before_redirect = ft_strjoin(tmp->before_redirect, str);
	}
	(*j) -= 2;
	ft_free_str(&str);
	return (CONTINUE);
}
