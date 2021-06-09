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
		// if (lst->env_arr[1] != NULL)
		// 	if (strcmp(lst->env_arr[1], "..") ==  0)
		// 		printf("SSSSS = %s\n", lst->env_arr[0]);
		(*del)(&lst->env_arr);
	}
	free(lst);
}
