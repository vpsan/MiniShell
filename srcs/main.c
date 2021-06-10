/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 17:29:03 by bhatches          #+#    #+#             */
/*   Updated: 2021/06/10 14:32:13 by bhatches         ###   ########.fr       */
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

	// test_env_split(prmtrs);							// leaks OK
	// test_env_lstsort_bubble(prmtrs);					// leaks OK
	// test_updatevalue_env_lst(prmtrs);				// leaks OK
	// test_builtin_env(prmtrs);						// leaks OK
	// test_builtin_unset(prmtrs);						// leaks OK
	// test_builtin_export_without_arguments(prmtrs);	// leaks OK
	// test_builtin_export_with_arguments(prmtrs);		// leaks OK
	// test_builtin_cd(prmtrs);							// leaks OK
	// test_builtin_echo(prmtrs);						// leaks OK
	//	cd		OK. But quit with return value is a queastion
	//	echo	OK
	//	env
	//	exit
	//	export
	//	pwd 	OK
	//	unset

	env_lstclear(&prmtrs.env_head, ft_free_str_arr);
	printf("Everything normal\n");
	// sleep(30);
	return (0);
}
