/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 17:29:03 by bhatches          #+#    #+#             */
/*   Updated: 2021/06/14 16:32:53 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
# include "my_structures.h"
#include "prsng_vldtn.h"
#include "my_shell.h"
#include "my_errors.h"
#include <stdbool.h>
#include <stdio.h>

void	putstr_greeting(void)
{
	ft_putstr_fd("\033[0;33m", 1);
	ft_putstr_fd("                             __         ____\n", 1);
	ft_putstr_fd("    ____ ___  __  __   _____/ /_  _____/ / / \n", 1);
	ft_putstr_fd("   / __ `__ \\/ / / /  / ___/ __ \\/ ___/ / /\n", 1);
	ft_putstr_fd("  / / / / / / /_/ /  (__  ) / / / ___/ / /\n", 1);
	ft_putstr_fd(" /_/ /_/ /_/\\__, /  /____/_/ /_/____/_/_/\n", 1);
	ft_putstr_fd("           /____/                         ....is now available for you!\n", 1);
	ft_putstr_fd("\n\n\n", 1);
	ft_putstr_fd("\033[0m", 1);
	return ;
}

int	main(int argc, char **argv, char **env)
{
	t_main	prmtrs;

	if (argc > 1)
		return (1);
	(void)argv;
	putstr_greeting();
	create_env_lst(&prmtrs, env);

	// TESTERS t_env_list:
	// test_env_split();								// leaks OK
	// test_env_lstsort_bubble(&prmtrs);				// leaks OK
	// test_updatevalue_env_lst(&prmtrs);				// leaks OK

	// TESTERS builtin
	// test_builtin_cd(&prmtrs);						// leaks OK
	// test_builtin_echo();								// leaks OK
	// test_builtin_env(&prmtrs);						// leaks OK
	// test_builtin_export_without_arguments(&prmtrs);	// leaks OK
	// test_builtin_export_with_arguments(&prmtrs);		// leaks OK
	// test_builtin_unset(&prmtrs);						// leaks OK
	// test_sort_unset(&prmtrs);						// leaks OK

	printf("\n-------------------\nEverything normal 1\n");
	env_lstclear(&prmtrs.env_head, ft_free_str_arr);
	printf("-------------------\nEverything normal 2\n-------------------\n");
	// sleep(10);
	return (0);
}
