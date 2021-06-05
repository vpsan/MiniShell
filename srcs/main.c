/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 17:29:03 by bhatches          #+#    #+#             */
/*   Updated: 2021/05/29 15:47:28 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "my_errors.h"
#include "prsng_vldtn.h"
#include "my_shell.h"
#include <stdbool.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_shell	prmtrs;


//	while (1)
//	{
///будет бесконечный цикл
		prsng_vldtn(&prmtrs);
		my_shell(&prmtrs);
	//	my_errors();
//	}
	return (0);
}
