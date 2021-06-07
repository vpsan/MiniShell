/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 12:19:21 by bhatches          #+#    #+#             */
/*   Updated: 2021/06/06 18:18:29 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(char **env_arr, int declare_flag)
{
	t_list	*p;

	p = (t_list *)malloc(1 * sizeof(t_list));
	if (p == NULL)
	{
		return (NULL);
	}
	p->env_arr = env_arr;
	p->declare_flag = declare_flag;
	p->next = NULL;
	return (p);
}
