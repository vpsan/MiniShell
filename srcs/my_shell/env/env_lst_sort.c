/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lst_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 19:38:43 by bhatches          #+#    #+#             */
/*   Updated: 2021/06/08 16:12:26 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_shell.h"
#include "libft.h"
#include "printf.h"

void 	swapLists(t_env_list **lst_1, t_env_list **lst_2)
{
	(*lst_1)->next = (*lst_2);
	(*lst_1) = (*lst_2);
	(*lst_2) = (*lst_2)->next;
	return ;
}

t_env_list	*mergeLists(t_env_list *a, t_env_list *b)
{
	t_env_list	tmp;
	t_env_list	*head;
	t_env_list	*c;
	int		result_minus_or_plus;

	head = &tmp;
	c = head;
	while ((a != 0) && (b != 0))
	{
		if (a->env_arr[0][0] < b->env_arr[0][0])
			swapLists(&c, &a);
		else
			swapLists(&c, &b);
	}
	if (a == 0)
		c->next = b;
	else
		c->next = a;
	return (head->next);
}

t_env_list	*env_lst_sort(t_env_list *c)
{
	t_env_list	*a;
	t_env_list	*b;

	a = c;
	b = c->next;
	if (c == 0 || c->next == 0)
		return (c);
	while ((b != 0) && (b->next != 0))
	{
		c = c->next;
		b = b->next->next;
	}
	b = c->next;
	c->next = 0;
	return (mergeLists(env_lst_sort(a), env_lst_sort(b)));
}
