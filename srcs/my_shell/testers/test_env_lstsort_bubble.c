/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_env_lstsort_bubble.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 22:10:03 by bhatches          #+#    #+#             */
/*   Updated: 2021/06/09 22:10:42 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_shell.h"

void 	test_env_lstsort_bubble(t_main prmtrs)
{
	{
		printf("/////////// PRINT LIST_ENV BEFORE SORT AND ADDING /////////\n");
		test_printf_all_env_lst(prmtrs.env_head);
	}

	env_lstadd_back(&prmtrs.env_head, env_lstnew(ft_split("A=0", '='),
											   0));
	env_lstadd_back(&prmtrs.env_head, env_lstnew(ft_split("a=1", '='),
											   0));
	env_lstadd_back(&prmtrs.env_head, env_lstnew(ft_split("b=1", '='),
											   0));
	env_lstadd_back(&prmtrs.env_head, env_lstnew(ft_split("c=2", '='),
											   0));

	env_lstsort_bubble(prmtrs.env_head);
	{
		printf("/////////// PRINT LIST_ENV AFTER SORT AND ADDING /////////\n");
		test_printf_all_env_lst(prmtrs.env_head);
	}
    return ;
}
