/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 17:29:03 by bhatches          #+#    #+#             */
/*   Updated: 2021/06/07 18:34:57 by bhatches         ###   ########.fr       */
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

	create_env_var(&prmtrs, env);

//	test_env_add(prmtrs);
//	test_builtins_env(prmtrs);
//	test_builtins_unset(prmtrs);
//	test_builtins_export_without_arguments(prmtrs);
//	test_builtins_export_with_arguments(prmtrs);

	ft_lstclear(&prmtrs.env_head, ft_free_str_arr);
	printf("Everything normal\n");
//	sleep(30);
	return (0);
}
