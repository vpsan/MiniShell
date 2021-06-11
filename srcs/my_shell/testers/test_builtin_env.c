/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_builtin_env.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 15:14:10 by bhatches          #+#    #+#             */
/*   Updated: 2021/06/08 16:09:23 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_shell.h"
#include "libft.h"
#include <printf.h>

void 	test_builtin_env(t_main *prmtrs)
{
	// printf list without adding elements in env:
	printf("-------------- ENV ORIGINAL -----------------\n");
	printf("-------------- ENV ORIGINAL -----------------\n");
	printf("-------------- ENV ORIGINAL -----------------\n");
	printf("-------------- ENV ORIGINAL -----------------\n\n");
	builtin_env(prmtrs);

	// printf list with adding elements in env:
	env_lstadd_back(&prmtrs->env_head, env_lstnew(env_split("W=www"),1));
	env_lstadd_back(&prmtrs->env_head, env_lstnew(env_split("X=xxx"),1));
	env_lstadd_back(&prmtrs->env_head, env_lstnew(env_split("Y="),1));
	env_lstadd_back(&prmtrs->env_head, env_lstnew(env_split("Z"),0));
	printf("-------------- ENV WITH ADDING ---------------\n");
	printf("-------------- ENV WITH ADDING ---------------\n");
	printf("-------------- ENV WITH ADDING ---------------\n");
	printf("-------------- ENV WITH ADDING ---------------\n\n");
	builtin_env(prmtrs);
	return ;
}