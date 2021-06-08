/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 14:48:36 by bhatches          #+#    #+#             */
/*   Updated: 2021/06/08 15:51:20 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_shell.h"

void	env_lstdelone(t_env_list *lst, void *(*del)(char ***arr))
{
	if ((*del) != NULL)
	{
		(*del)(&lst->env_arr);
	}
	free(lst);
}
