/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_execve.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 17:54:15 by bhatches          #+#    #+#             */
/*   Updated: 2021/06/14 20:26:46 by bhatches         ###   ########.fr       */
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

	// example 0
	char **cmnd_words;
	cmnd_words = (char **)malloc(sizeof(char *) * 5);
	cmnd_words[0] = ft_strdup("ls\0");
	cmnd_words[1] = ft_strdup("..\0");
	cmnd_words[2] = NULL;
	cmnd_words[3] = NULL;
	cmnd_words[4] = NULL;

    char    argv[3] = "ls\0";
    char    *tmp;
    char    *final;
    while (*path_arr != NULL)
    {
        tmp = ft_strjoin(*path_arr, "/");
        final = ft_strjoin(tmp, argv);
        execve(final, cmnd_words, env);
        printf("%s\n", final);
        path_arr++;
    }
    return (0);
}
