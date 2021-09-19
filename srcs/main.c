/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 17:29:03 by bhatches          #+#    #+#             */
/*   Updated: 2021/09/17 01:48:25 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "my_structures.h"
#include "prsng_vldtn.h"
#include "my_shell.h"
#include <stdio.h>

void	putstr_greeting(void)
{
	ft_putstr_fd("\033[0;33m", 1);
	ft_putstr_fd("                             __         ____\n", 1);
	ft_putstr_fd("    ____ ___  __  __   _____/ /_  _____/ / / \n", 1);
	ft_putstr_fd("   / __ `__ \\/ / / /  / ___/ __ \\/ ___/ / /\n", 1);
	ft_putstr_fd("  / / / / / / /_/ /  (__  ) / / / ___/ / /\n", 1);
	ft_putstr_fd(" /_/ /_/ /_/\\__, /  /____/_/ /_/____/_/_/\n", 1);
	ft_putstr_fd("           /____/                         ....is now", 1);
	ft_putstr_fd(" available for you!\n\n", 1);
	ft_putstr_fd("\n\n\n", 1);
	ft_putstr_fd("\033[0m", 1);
	return ;
}

void	routine_parsing_executing(t_main *prmtrs)
{
	int		parinsg_validation_result;

	prmtrs->cmd_head = NULL;
	prmtrs->exit_status = 0;
	while (true)
	{
		parinsg_validation_result = prsng_vldtn(prmtrs);
		if (parinsg_validation_result == NOT_EXECUTE)
			continue ;
		else if (parinsg_validation_result == EXECUTE)
			my_shell(prmtrs);
	}
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
	routine_parsing_executing(&prmtrs);
	return (0);
}
