/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lstadd_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 22:15:58 by bhatches          #+#    #+#             */
/*   Updated: 2021/06/09 22:16:01 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_shell.h"

void	env_lstadd_front(t_env_list **lst, t_env_list *new)
{
	t_env_list	*buf;

	if (*lst == NULL)
	{
		*lst = new;
	}
	else if (new == NULL)
	{
		return ;
	}
	else
	{
		buf = *lst;
		*lst = new;
		new->next = buf;
	}
}
