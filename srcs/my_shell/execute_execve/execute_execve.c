/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_execve.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 17:54:15 by bhatches          #+#    #+#             */
/*   Updated: 2021/06/19 14:36:55 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_shell.h"

int     execute_execve(t_main *prmtrs)
{
    char    **env;
    char    *paths;
    char    **path_arr;

    env = env_create_arr(prmtrs->env_head);//создаем (char **env) из листа (prmtrs->env_head) так как думерный массив env нужен чтобы выполнить системый вызов execve
    paths = getvalue_env_lst("PATH", prmtrs->env_head);//получаем PATH
    path_arr = ft_split(paths, ':');// PATH делим на кусочки по ":" 

	// example 0 START
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
    while (*path_arr != NULL) // пока не пройдемся по всес кусочкам PATH
    {
        tmp = ft_strjoin(*path_arr, "/");// сначала strjoin-ним "/". Чтобы получить "path_arr/"
        final = ft_strjoin(tmp, argv);// потом strjoin-ним "функцию". Чтобы получить "path_arr/функция"
		// tmp и final - замолоченны. ИХ нужно отчистить.
		printf("%s\n", final);// просто проверка что получили в итоге
        execve(final, cmnd_words, env);
        path_arr++;
    }
	// example 0 END
	
	ft_free_str_arr(&env);
    return (0);
}
