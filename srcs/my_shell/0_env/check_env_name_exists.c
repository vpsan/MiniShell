/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_env_name_exists.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 11:02:34 by bhatches          #+#    #+#             */
/*   Updated: 2021/09/05 23:12:37 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_shell.h"

int	check_env_name_exists(char *name, t_env_list *env_head)
{
	while (env_head != NULL)
	{
		if (strcmp(name, env_head->env_arr[0]) == 0)
			return (true);
		env_head = env_head->next;
	}
	return (false);
}
