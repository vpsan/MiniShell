/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 20:04:06 by bhatches          #+#    #+#             */
/*   Updated: 2021/06/12 11:08:37 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_shell.h"

int 	print_export_declare_x(t_env_list *env_head, int out_fd)
{
	t_env_list	*tmp;

	env_lstsort_bubble(env_head);
	tmp = env_head;
	while (tmp != NULL)
	{
		ft_putstr_fd("declare -x ", out_fd);
		ft_putstr_fd(tmp->env_arr[0], out_fd);
		if (tmp->env_arr[1] == NULL)
			ft_putstr_fd("\n", out_fd);
		else
		{
			ft_putstr_fd("=\"", out_fd);
			ft_putstr_fd(tmp->env_arr[1], out_fd);
			ft_putstr_fd("\"\n", out_fd);
		}
		tmp = tmp->next;
	}
	return (0);
}

int 	builtin_export(char **cmnd_words, t_env_list **env_head, int out_fd)
{
	char	**arr;
	int		i;
	char	*name;

	if (cmnd_words[1] == NULL)
		return (print_export_declare_x(*env_head, out_fd));
	else
	{
		i = 1;
		while (cmnd_words[i] != NULL)
		{
			name = ft_strdup_sep(cmnd_words[i], '=');
			if (check_env_name_exists(name, *env_head) == true)
				unset_delete_lst_element(name, env_head);
			ft_free_str(&name);
			arr = env_split(cmnd_words[i]);
			if (arr[1] == NULL)
				env_lstadd_back(env_head, env_lstnew(arr, 0));
			else
				env_lstadd_back(env_head, env_lstnew(arr, 1));
			i++;
		}
	}
	return (0);
}
