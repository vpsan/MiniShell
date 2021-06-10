/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 20:04:06 by bhatches          #+#    #+#             */
/*   Updated: 2021/06/10 16:12:51 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_shell.h"

int 	print_export_declare_x(t_env_list *env_head)
{
	t_env_list	*tmp;
	int			fd;

	fd = 1;
	env_lstsort_bubble(env_head);
	tmp = env_head;
	while(tmp != NULL)
	{
		ft_putstr_fd("declare -x ", fd);
		ft_putstr_fd(tmp->env_arr[0], fd);
		if (tmp->env_arr[1] == NULL)
			ft_putstr_fd("\n", fd);
		else
		{
			ft_putstr_fd("=\"", fd);
			ft_putstr_fd(tmp->env_arr[1], fd);
			ft_putstr_fd("\"\n", fd);
		}
		tmp = tmp->next;
	}
	return (1);
}

int 	builtin_export(char **cmnd_words, t_env_list *env_head)
{
	char 	**arr;
	int		i;


	if (cmnd_words[1] == NULL)
	{
		print_export_declare_x(env_head);
		return (0);
	}
	else
	{
		i = 1;
		while (cmnd_words[i] != NULL)
		{
			arr = env_split(cmnd_words[i]);
			if (arr[1] == NULL)
				env_lstadd_back(&env_head, env_lstnew(arr, 0));
			else
				env_lstadd_back(&env_head, env_lstnew(arr, 1));
			i++;
		}
	}
	return (0);
}
