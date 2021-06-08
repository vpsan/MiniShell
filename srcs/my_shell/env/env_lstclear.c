/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lstclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 18:43:45 by bhatches          #+#    #+#             */
/*   Updated: 2021/06/08 16:12:26 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_shell.h"

void	env_lstclear(t_env_list **lst, void *(*del)(char ***arr))
{
	if (*lst && lst)
	{
		env_lstclear(&(*lst)->next, del);
		env_lstdelone(*lst, del);
		*lst = NULL;
	}
}
