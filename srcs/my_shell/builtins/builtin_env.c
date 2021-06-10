/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 15:40:13 by bhatches          #+#    #+#             */
/*   Updated: 2021/06/10 14:40:39 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_shell.h"

int     builtin_env(t_main *prmtrs)
{
    t_env_list  *tmp;
    int         fd;

    fd = 1;
    tmp = prmtrs->env_head;
    while (tmp != NULL)
    {
        if (tmp->declare_flag != 0)
        {
            ft_putstr_fd(tmp->env_arr[0], fd);
            ft_putstr_fd("=", fd);
            ft_putstr_fd(tmp->env_arr[1], fd);
            ft_putstr_fd("\n", fd);
        }
        tmp = tmp->next;
    }
    return (0);
}
