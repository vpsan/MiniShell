/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_env_create_arr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 17:31:20 by bhatches          #+#    #+#             */
/*   Updated: 2021/06/14 17:47:58 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_shell.h"

void		test_env_create_arr(t_main *prmtrs)
{
    char    **string_arr;

    env_lstadd_back(&prmtrs->env_head, env_lstnew(env_split("new1=1"),1));
	env_lstadd_back(&prmtrs->env_head, env_lstnew(env_split("new2=2"),1));
	env_lstadd_back(&prmtrs->env_head, env_lstnew(env_split("new3="),1));
	env_lstadd_back(&prmtrs->env_head, env_lstnew(env_split("new4"),1));    

    string_arr = env_create_arr(prmtrs->env_head);
    int i = 0;
    while (string_arr[i] != NULL)
    {
        printf("%s\n", string_arr[i]);
        i++;
    }
    ft_free_str_arr(&string_arr);
	return ;
}