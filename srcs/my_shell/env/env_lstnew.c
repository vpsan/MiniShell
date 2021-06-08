/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 12:19:21 by bhatches          #+#    #+#             */
/*   Updated: 2021/06/08 15:51:30 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_shell.h"

t_env_list	*env_lstnew(char **env_arr, int declare_flag)
{
	t_env_list	*p;

	p = (t_env_list *)malloc(1 * sizeof(t_env_list));
	if (p == NULL)
	{
		return (NULL);
	}
	p->env_arr = env_arr;
	p->declare_flag = declare_flag;
	p->next = NULL;
	return (p);
}
