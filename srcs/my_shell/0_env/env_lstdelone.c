/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 22:16:36 by bhatches          #+#    #+#             */
/*   Updated: 2021/09/05 22:38:37 by bhatches         ###   ########.fr       */
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
