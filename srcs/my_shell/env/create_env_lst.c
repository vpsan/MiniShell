/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_env_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 20:06:36 by bhatches          #+#    #+#             */
/*   Updated: 2021/06/19 14:03:45 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_shell.h"
#include "libft.h"
#include "printf.h"

void	create_env_lst(t_main *prmtrs, char **env)
{
	int	i;

	i = 0;
	prmtrs->env_head = NULL;
	while (env[i] != NULL)
	{
		env_lstadd_back(&prmtrs->env_head, env_lstnew(env_split(env[i]), 1));
		i++;
	}
	return ;
}
