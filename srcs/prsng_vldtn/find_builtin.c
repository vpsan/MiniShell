/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 09:54:32 by bhatches          #+#    #+#             */
/*   Updated: 2021/09/16 09:54:33 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prsng_vldtn.h"

int	find_builtin(t_cmd_list *tmp, int i)
{
	int		j;
	char	*str;

	j = 0;
	while (tmp->orig_cmnd_str[i] && !ft_isspace(tmp->orig_cmnd_str[i + 1]))
	{
		j += 1;
		i++;
	}
	str = ft_substr(tmp->orig_cmnd_str, (i - j), (i + 1));
	str = delete_spaces(str);
	if ((ft_strcmp(str, "env") == 0) || (ft_strcmp(str, "export") == 0)
		|| (ft_strcmp(str, "unset") == 0) || (ft_strcmp(str, "echo") == 0)
		|| (ft_strcmp(str, "cd") == 0) || (ft_strcmp(str, "pwd") == 0)
		|| (ft_strcmp(str, "exit") == 0))
	{
		tmp->is_builtin = true;
		ft_free_str(&str);
		return (1);
	}
	ft_free_str(&str);
	return (0);
}
