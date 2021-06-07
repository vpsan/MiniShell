/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_env_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 18:19:52 by bhatches          #+#    #+#             */
/*   Updated: 2021/06/07 18:30:39 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
# include "my_structures.h"
#include "prsng_vldtn.h"
#include "my_shell.h"
#include "my_errors.h"
#include <stdbool.h>
#include <stdio.h>

void 	test_env_add(t_main prmtrs)
{
	{
		printf("/////////// PRINT LIST_ENV BEFORE SORT AND ADDING /////////\n");
		test_printf_all_List_env(prmtrs.env_head);
	}

	ft_lstadd_back(&prmtrs.env_head, ft_lstnew(ft_split("A=0", '='),
											   0));
	ft_lstadd_back(&prmtrs.env_head, ft_lstnew(ft_split("a=1", '='),
											   0));
	ft_lstadd_back(&prmtrs.env_head, ft_lstnew(ft_split("b=1", '='),
											   0));
	ft_lstadd_back(&prmtrs.env_head, ft_lstnew(ft_split("c=2", '='),
											   0));

	prmtrs.env_head = ft_lst_Sort(prmtrs.env_head);
	{
		printf("/////////// PRINT LIST_ENV AFTER SORT AND ADDING /////////\n");
		test_printf_all_List_env(prmtrs.env_head);
	}
    return ;
}
