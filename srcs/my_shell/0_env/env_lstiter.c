/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lstiter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 22:16:56 by bhatches          #+#    #+#             */
/*   Updated: 2021/06/09 22:16:57 by bhatches         ###   ########.fr       */
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
