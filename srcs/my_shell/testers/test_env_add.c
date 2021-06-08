/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_env_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 18:19:52 by bhatches          #+#    #+#             */
/*   Updated: 2021/06/08 16:09:23 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_shell.h"
#include "libft.h"
#include <printf.h>

void 	test_env_add(t_main prmtrs)
{
	{
		printf("/////////// PRINT LIST_ENV BEFORE SORT AND ADDING /////////\n");
		test_printf_all_List_env(prmtrs.env_head);
	}

	env_lstadd_back(&prmtrs.env_head, env_lstnew(ft_split("A=0", '='),
											   0));
	env_lstadd_back(&prmtrs.env_head, env_lstnew(ft_split("a=1", '='),
											   0));
	env_lstadd_back(&prmtrs.env_head, env_lstnew(ft_split("b=1", '='),
											   0));
	env_lstadd_back(&prmtrs.env_head, env_lstnew(ft_split("c=2", '='),
											   0));

	prmtrs.env_head = env_lst_sort(prmtrs.env_head);
	{
		printf("/////////// PRINT LIST_ENV AFTER SORT AND ADDING /////////\n");
		test_printf_all_List_env(prmtrs.env_head);
	}
    return ;
}
