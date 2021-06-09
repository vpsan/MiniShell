/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lstsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 22:18:15 by bhatches          #+#    #+#             */
/*   Updated: 2021/06/09 22:18:36 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_shell.h"

int	env_lstsize(t_env_list *lst)
{
	int			count;
	t_env_list	*p;

	p = lst;
	count = 0;
	while (p != NULL)
	{
		p = p->next;
		count++;
	}
	return (count);
}
