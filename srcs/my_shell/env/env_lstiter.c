/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 18:56:55 by bhatches          #+#    #+#             */
/*   Updated: 2021/06/08 15:51:22 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_shell.h"

void	env_lstiter(t_env_list *lst, void (*f)(void *))
{
	t_env_list	*p;

	p = lst;
	if (f != NULL)
	{
		while (p != NULL)
		{
			f(p->env_arr);
			p = p->next;
		}
	}
}
