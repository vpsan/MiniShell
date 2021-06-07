/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_mergeSort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 19:38:43 by bhatches          #+#    #+#             */
/*   Updated: 2021/06/06 19:38:48 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_shell.h"
#include "libft.h"
#include "printf.h"

void 	swapLists(t_list **lst_1, t_list **lst_2)
{
	(*lst_1)->next = (*lst_2);
	(*lst_1) = (*lst_2);
	(*lst_2) = (*lst_2)->next;
	return ;
}

t_list	*mergeLists(t_list *a, t_list *b)
{
	t_list	tmp;
	t_list	*head;
	t_list	*c;
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

t_list	*ft_lst_Sort(t_list *c)
{
	t_list	*a;
	t_list	*b;

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
	return (mergeLists(ft_lst_Sort(a), ft_lst_Sort(b)));
}
