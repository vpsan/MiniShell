/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 15:40:13 by bhatches          #+#    #+#             */
/*   Updated: 2021/06/08 16:12:26 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_shell.h"

int     builtin_env(t_main *prmtrs)
{
    t_env_list  *tmp;

    tmp = prmtrs->env_head;
    while (tmp != NULL)
    {
        if (tmp->declare_flag != 0)
            printf("%s=%s\n", tmp->env_arr[0], tmp->env_arr[1]);
        tmp = tmp->next;
    }
    return (0);
}
