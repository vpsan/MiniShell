/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_builtin_unset.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 15:14:36 by bhatches          #+#    #+#             */
/*   Updated: 2021/06/08 16:09:23 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_shell.h"
#include "libft.h"
#include <printf.h>

void 	test_builtin_unset(t_main *prmtrs)
{
	printf("-------------- ENV BEFORE UNSET -----------------\n");
	printf("-------------- ENV BEFORE UNSET -----------------\n");
	printf("-------------- ENV BEFORE UNSET -----------------\n");
	printf("-------------- ENV BEFORE UNSET -----------------\n");
	// adding to List_env:
	env_lstadd_back(&prmtrs->env_head, env_lstnew(env_split("A=0"),1));
	env_lstadd_back(&prmtrs->env_head, env_lstnew(env_split("B=0"),1));
	print_export_declare_x(prmtrs->env_head, 1);

	printf("-------------- ENV AFTER UNSET -----------------\n");
	printf("-------------- ENV AFTER UNSET -----------------\n");
	printf("-------------- ENV AFTER UNSET -----------------\n");
	printf("-------------- ENV AFTER UNSET -----------------\n");
	// deleting from List_env:
	char **cmnd_words;
	cmnd_words = (char **)malloc(sizeof(char *) * 9);
	cmnd_words[0] = ft_strdup("unset\0");
	cmnd_words[1] = ft_strdup("A\0");
	cmnd_words[2] = ft_strdup("a\0");
	cmnd_words[3] = ft_strdup("a=1\0");
	cmnd_words[4] = ft_strdup("1a\0");
	cmnd_words[5] = ft_strdup("-a\0");
	cmnd_words[6] = ft_strdup("=\0");//doesnt work
	cmnd_words[7] = ft_strdup("B\0");
	cmnd_words[8] = NULL;
	builtin_unset(cmnd_words, &(prmtrs->env_head));
	print_export_declare_x(prmtrs->env_head, 1);

	ft_free_str_arr(&cmnd_words);
	return ;
}