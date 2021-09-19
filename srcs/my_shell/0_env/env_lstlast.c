/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lstlast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 22:17:18 by bhatches          #+#    #+#             */
/*   Updated: 2021/06/09 22:17:20 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_shell.h"

t_env_list	*env_lstlast(t_env_list *lst)
{
	t_env_list	*p;

	if (lst == NULL)
	{
		return (NULL);
	}
	p = lst;
	while (p->next != NULL)
	{
		p = p->next;
	}
	return (p);
}
