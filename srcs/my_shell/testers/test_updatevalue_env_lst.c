/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_updatevalue_env_lst.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 15:15:58 by bhatches          #+#    #+#             */
/*   Updated: 2021/06/09 19:00:51 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_shell.h"

void 		test_updatevalue_env_lst(t_main prmtrs)
{
	char *s1 = getcwd(NULL, 0);
	char *s2 = getcwd(NULL, 0);

	env_lstadd_back(&prmtrs.env_head, env_lstnew(ft_split("Z1=", '='), 1));
	env_lstadd_back(&prmtrs.env_head, env_lstnew(ft_split("Z2=new", '='), 1));
	updatevalue_env_lst("Z1", s1, &prmtrs.env_head);
	updatevalue_env_lst("Z2", s2, &prmtrs.env_head);
	print_export_declare_x(prmtrs.env_head);
	return ;
}
