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
#include "libft.h"

void 	test_builtins_export_without_arguments(t_main prmtrs)
{
	ft_lstadd_back(&prmtrs.env_head, ft_lstnew(ft_split("A=0", '='), 0));
	ft_lstadd_back(&prmtrs.env_head, ft_lstnew(ft_split("B", '='), 1));
	ft_lstadd_back(&prmtrs.env_head, ft_lstnew(ft_split("C=", '='), 1));

	char **cmnd_words;
	cmnd_words = (char **)malloc(sizeof(char *) * 3);
	cmnd_words[0] = NULL;
	cmnd_words[1] = NULL;
	cmnd_words[2] = NULL;
	export(cmnd_words, prmtrs.env_head);

	ft_free_str_arr(&cmnd_words);
	return ;
}

void 	test_builtins_export_with_arguments(t_main prmtrs)
{
	char **cmnd_words;
	cmnd_words = (char **)malloc(sizeof(char *) * 5);

//	// example 1
//	cmnd_words[0] = ft_strdup("export\0");
//	cmnd_words[1] = ft_strdup("A=0\0");
//	cmnd_words[2] = NULL;
//	cmnd_words[3] = NULL;
//	cmnd_words[4] = NULL;

	// example 2
	cmnd_words[0] = ft_strdup("export\0");
	cmnd_words[1] = ft_strdup("A=0\0");
	cmnd_words[2] = ft_strdup("B=\0");
	cmnd_words[3] = ft_strdup("C\0");
	cmnd_words[4] = NULL;

//	// example 3
//	cmnd_words[0] = ft_strdup("export\0");
//	cmnd_words[1] = ft_strdup("A=0\0");
//	cmnd_words[2] = NULL;
//	cmnd_words[3] = NULL;
//	cmnd_words[4] = NULL;

	export(cmnd_words, prmtrs.env_head);
	env(&prmtrs);

	printf("-------------------------------\n");

	char **NULL_arr;
	NULL_arr = (char **)malloc(sizeof(char *) * 2);
	NULL_arr[0] = ft_strdup("export\0");
	NULL_arr[1] = NULL;
	export(NULL_arr, prmtrs.env_head);


	ft_free_str_arr(&cmnd_words);
	return ;
}