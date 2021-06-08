/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_builtins_export.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 11:02:42 by bhatches          #+#    #+#             */
/*   Updated: 2021/06/08 11:02:45 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_shell.h"

void 	test_builtins_export(t_main prmtrs)
{
	ft_lstadd_back(&prmtrs.env_head, ft_lstnew(ft_split("A=0", '='), 0));
	ft_lstadd_back(&prmtrs.env_head, ft_lstnew(ft_split("B", '='), 1));

	char **cmnd_words;
	cmnd_words = (char **)malloc(sizeof(char *) * 3);
	cmnd_words[0] = NULL;
	cmnd_words[1] = NULL;
	cmnd_words[2] = NULL;
	export(cmnd_words, prmtrs.env_head);

	return ;
}
