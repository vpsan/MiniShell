/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 17:29:03 by bhatches          #+#    #+#             */
/*   Updated: 2021/06/14 19:04:13 by bhatches         ###   ########.fr       */
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
	ft_putstr_fd("           /____/                         ....is now available for you!\n\n", 1);
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

	// // TESTERS t_env_list:
	// printf("\n---------------------------------------------------------------------- TEST 0.1\n");
	// test_env_split();								// leaks OK
	// printf("\n---------------------------------------------------------------------- TEST 0.2\n");
	// test_env_lstsort_bubble(&prmtrs);				// leaks OK
	// printf("\n---------------------------------------------------------------------- TEST 0.3\n");
	// test_updatevalue_env_lst(&prmtrs);				// leaks OK
	// printf("\n---------------------------------------------------------------------- TEST 0.4\n");
	// test_env_create_arr(&prmtrs);					// leaks OK
	// printf("\n---------------------------------------------------------------------- TEST 0.5\n");

	// // TESTERS builtin
	// printf("\n---------------------------------------------------------------------- TEST 1.1\n");
	// test_builtin_cd(&prmtrs);						// leaks OK
	// printf("\n---------------------------------------------------------------------- TEST 1.2\n");
	// test_builtin_echo();								// leaks OK
	// printf("\n---------------------------------------------------------------------- TEST 1.3\n");
	// test_builtin_env(&prmtrs);						// leaks OK
	// printf("\n---------------------------------------------------------------------- TEST 1.4\n");
	// test_builtin_export_without_arguments(&prmtrs);	// leaks OK
	// printf("\n---------------------------------------------------------------------- TEST 1.5\n");
	// test_builtin_export_with_arguments(&prmtrs);		// leaks OK
	// printf("\n---------------------------------------------------------------------- TEST 1.6\n");
	// test_builtin_unset(&prmtrs);						// leaks OK
	// printf("\n---------------------------------------------------------------------- TEST 1.7\n");
	// test_sort_unset(&prmtrs);						// leaks OK
	// printf("\n---------------------------------------------------------------------- TEST 1.8\n");

	execute_execve(&prmtrs);

	printf("\n-------------------\nEverything normal 1\n");
	env_lstclear(&prmtrs.env_head, ft_free_str_arr);
	printf("-------------------\nEverything normal 2\n-------------------\n");
	// sleep(10);
	return (0);
}
