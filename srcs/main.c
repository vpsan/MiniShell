/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 17:29:03 by bhatches          #+#    #+#             */
/*   Updated: 2021/06/12 11:12:14 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
# include "my_structures.h"
#include "prsng_vldtn.h"
#include "my_shell.h"
#include "my_errors.h"
#include <stdbool.h>
#include <stdio.h>

int	main(int argc, char **argv, char **env)
{
	t_main	prmtrs;

	if (argc > 1)
		return (1);
	(void)argv;
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

	//	cd		OK.	N.	fd no. 	But queastion with return value
	//	echo	OK.	N.	fd yes. fd done +
	//	env		OK.	N.	fd yes. fd done +
	//	export	OK.	N.	fd yes. fd done	+
	//	pwd 	OK.	N.	fd yes. fd done +
	//	unset	OK.	N.	fd no.
	//	exit

	printf("\n-------------------\nEverything normal 1\n");
	env_lstclear(&prmtrs.env_head, ft_free_str_arr);
	printf("-------------------\nEverything normal 2\n-------------------\n");
	sleep(10);
	return (0);
}
