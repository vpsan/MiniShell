/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 17:29:03 by bhatches          #+#    #+#             */
/*   Updated: 2021/06/07 17:11:02 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
# include "my_structures.h"
#include "prsng_vldtn.h"
#include "my_shell.h"
#include "my_errors.h"
#include <stdbool.h>
#include <stdio.h>

void 	test_env(t_main prmtrs)
{
	{
		printf("/////////// PRINT LIST_ENV BEFORE SORT AND ADDING /////////\n");
		ft_lst_test_printf(prmtrs.env_head);
	}

	ft_lstadd_back(&prmtrs.env_head, ft_lstnew(ft_split("AB=0", '='),
											   0));
	ft_lstadd_back(&prmtrs.env_head, ft_lstnew(ft_split("c=0", '='),
											   0));
	ft_lstadd_back(&prmtrs.env_head, ft_lstnew(ft_split("ab=1", '='),
											   0));
	ft_lstadd_back(&prmtrs.env_head, ft_lstnew(ft_split("aac=2", '='),
											   0));

	prmtrs.env_head = ft_lst_Sort(prmtrs.env_head);
	{
		printf("/////////// PRINT LIST_ENV AFTER SORT AND ADDING /////////\n");
		ft_lst_test_printf(prmtrs.env_head);
	}
}

int	main(int argc, char **argv, char **env)
{
	t_main	prmtrs;

	create_env_var(&prmtrs, env);

	// test_env(prmtrs);
	ft_env(&prmtrs);
	
	ft_lstclear(&prmtrs.env_head, ft_free_str_arr);
	printf("Everything normal\n");

//	sleep(30);
	return (0);
}
