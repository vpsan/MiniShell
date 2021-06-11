/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 17:29:03 by bhatches          #+#    #+#             */
/*   Updated: 2021/06/10 16:18:33 by bhatches         ###   ########.fr       */
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

//	test_env_split();								// leaks OK
//	test_env_lstsort_bubble(&prmtrs);				// leaks OK
//	test_updatevalue_env_lst(&prmtrs);				// leaks OK

//	test_builtin_cd(&prmtrs);						// leaks OK
//	test_builtin_echo();							// leaks OK
//	test_builtin_env(&prmtrs);						// leaks OK
//	test_builtin_export_without_arguments(&prmtrs);	// leaks OK
//	test_builtin_export_with_arguments(&prmtrs);	// leaks OK
//	test_builtin_unset(&prmtrs);					// leaks OK
//	test_sort_unset(&prmtrs);						// leaks OK

	//	cd		N.	fd no. 	But queastion with return value
	//	echo	N.	fd yes. fd done +
	//	env		N.	fd yes. fd done +
	//	export	N.	fd yes. fd done	+
	//	pwd 	N.	fd yes. fd done +
	//	unset	N.	fd no.
	//	exit

	printf("Everything normal 1\n");
	env_lstclear(&prmtrs.env_head, ft_free_str_arr);
	printf("Everything normal 2\n");
	sleep(10);
	return (0);
}
