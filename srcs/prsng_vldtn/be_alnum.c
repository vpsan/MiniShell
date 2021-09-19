/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   be_alnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 09:53:03 by bhatches          #+#    #+#             */
/*   Updated: 2021/09/16 09:53:04 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prsng_vldtn.h"

int	condition(int j, t_cmd_list *tmp)
{
	if (j > 0 && !ft_isspace(tmp->orig_cmnd_str[j - 1])
		&& tmp->orig_cmnd_str[j] != '>'
		&& tmp->orig_cmnd_str[j] != '<')
		return (CONTINUE);
	return (BREAK);
}

int	stop(char **str)
{
	ft_free_str(str);
	return (BREAK);
}

int	be_alnum(int *j, t_cmd_list *tmp)
{
	int		len;
	char	*str;
	char	*ex;

	len = 0;
	while (condition(*j, tmp) == CONTINUE)
	{
		(*j)--;
		len += 1;
	}
	len += 1;
	str = ft_substr(tmp->orig_cmnd_str, (*j), len);
	if (find_builtin(tmp, (*j)) == 1)
		return (stop(&str));
	else
	{
		ex = ft_strdup(tmp->before_redirect);
		ft_free_str(&tmp->before_redirect);
		tmp->before_redirect = ft_strjoin(ex, str);
		ft_free_str(&ex);
	}
	(*j) -= 1;
	ft_free_str(&str);
	return (CONTINUE);
}
