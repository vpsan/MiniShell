/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_create_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 17:03:13 by bhatches          #+#    #+#             */
/*   Updated: 2021/06/14 17:49:33 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_shell.h"

static char *create_line_from_NameValue(t_env_list *tmp)
{
    char    *result_1st_join;
    char    *result_2nd_join;

    if (tmp->env_arr[1] == NULL)
        return (strdup(tmp->env_arr[0]));
    else if (ft_strlen(tmp->env_arr[1]) == 0)
       return (ft_strjoin(tmp->env_arr[0], "="));
    else
    {
        result_1st_join = ft_strjoin(tmp->env_arr[0], "=");
        result_2nd_join = ft_strjoin(result_1st_join, tmp->env_arr[1]);
        ft_free_str(&result_1st_join);
        return (result_2nd_join);
    }
}

char		**env_create_arr(t_env_list *env_head)
{
    char        **env;
    t_env_list  *tmp;
	int 		i;

    env = (char **)malloc(sizeof(char *) * (env_lstsize(env_head) + 1));
    tmp = env_head;
    i = 0;
    while (tmp != NULL)
    {
        env[i] = create_line_from_NameValue(tmp);
        i++;
        tmp = tmp->next;
    }
    env[i] = NULL;
    return (env);
}