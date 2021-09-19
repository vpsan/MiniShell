/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lstmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 20:17:25 by bhatches          #+#    #+#             */
/*   Updated: 2021/06/09 22:17:52 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_shell.h"

t_env_list	*env_lstmap(t_env_list *lst, void *(*f)(void *),
											void *(*del)(char ***))
{
	t_env_list	*new_begin;
	t_env_list	*p;

	if (lst == NULL)
		return (NULL);
	new_begin = env_lstnew(f(lst->env_arr), 1);
	if (new_begin == NULL)
	{
		return (NULL);
	}
	p = new_begin;
	lst = lst->next;
	while (lst != NULL)
	{
		p = env_lstnew(f(lst->env_arr), 1);
		if (p == NULL)
		{
			env_lstclear(&new_begin, del);
			return (NULL);
		}
		env_lstadd_back(&new_begin, p);
		lst = lst->next;
	}
	return (new_begin);
}
