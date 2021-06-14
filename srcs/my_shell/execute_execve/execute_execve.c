/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_execve.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 17:54:15 by bhatches          #+#    #+#             */
/*   Updated: 2021/06/14 18:37:49 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_shell.h"

int     execute_execve(t_main *prmtrs)
{
    char    **env;
    char    *paths;
    char    **path_arr;

    env = env_create_arr(prmtrs->env_head);
    paths = getvalue_env_lst("PATH", prmtrs->env_head);
    path_arr = ft_split(paths, ':');
    
    // while (*path_arr != NULL)
    // {
    //     printf("%s\n", *path_arr);
    //     path_arr++;
    // }

    char    argv[3] = "ls\0";
    char    *tmp;
    char    *final;
    while (*path_arr != NULL)
    {
        tmp = ft_strjoin(*path_arr, "/");
        final = ft_strjoin(tmp, argv);
        printf("%s\n", final);
        path_arr++;
    }
    return (0);
}
