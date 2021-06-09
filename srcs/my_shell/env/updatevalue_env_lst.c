/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updatevalue_env_lst.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:47:49 by bhatches          #+#    #+#             */
/*   Updated: 2021/06/09 20:34:33 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_shell.h"

void    updatevalue_env_lst(char *name,
							char *malloced_new_value, t_env_list **env_head)
{
    t_env_list  *tmp;
    char        **new_arr;

    tmp = *env_head;
    while(tmp != NULL)
    {
        if (strcmp(name, tmp->env_arr[0]) == 0)
        {
            if (tmp->env_arr[1] != NULL)
            {
                ft_free_str(&tmp->env_arr[1]);
				tmp->env_arr[1] = malloced_new_value;
                printf("1\n");
                printf("p = %p\n", tmp->env_arr[1]);
                printf("p = %p\n", malloced_new_value);
            }
            else
            {
                ft_free_str_arr(&tmp->env_arr);
                new_arr = (char **)malloc(sizeof(char *) * 3);
                new_arr[0] = ft_strdup(name);
                new_arr[1] = malloced_new_value;
                printf("2\n");
                printf("p = %p\n", tmp->env_arr[1]);
                printf("p = %p\n", malloced_new_value);
                new_arr[2] = NULL;
				tmp->env_arr = new_arr;
            }
        }
        tmp = tmp->next;
    }
    return ;
}
