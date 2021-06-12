/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_builtin_export.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 11:02:42 by bhatches          #+#    #+#             */
/*   Updated: 2021/06/12 11:19:34 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_shell.h"
#include "libft.h"
#include <printf.h>

void 	test_builtin_export_without_arguments(t_main *prmtrs)
{
	env_lstadd_back(&prmtrs->env_head, env_lstnew(env_split("A=0"), 0));
	env_lstadd_back(&prmtrs->env_head, env_lstnew(env_split("B"), 1));
	env_lstadd_back(&prmtrs->env_head, env_lstnew(env_split("C="), 1));
	env_lstadd_back(&prmtrs->env_head, env_lstnew(env_split("ab="), 1));
	env_lstadd_back(&prmtrs->env_head, env_lstnew(env_split("aab=new1"), 1));

	char **cmnd_words;
	cmnd_words = (char **)malloc(sizeof(char *) * 3);
	cmnd_words[0] = NULL;
	cmnd_words[1] = NULL;
	cmnd_words[2] = NULL;
	builtin_export(cmnd_words, &prmtrs->env_head, 1);

	ft_free_str_arr(&cmnd_words);
	return ;
}

void 	test_builtin_export_with_arguments(t_main *prmtrs)
{
	// Printf list without adding elements in env:
	printf("-------------- EXPORT ENV BEFORE ADDING  -----------------\n");
	printf("-------------- EXPORT ENV BEFORE ADDING  -----------------\n");
	printf("-------------- EXPORT ENV BEFORE ADDING  -----------------\n");
	printf("-------------- EXPORT ENV BEFORE ADDING  -----------------\n");
	printf("-------------- EXPORT ENV BEFORE ADDING  -----------------\n\n");
	env_lstadd_back(&prmtrs->env_head, env_lstnew(env_split("A=0"), 0));
	env_lstadd_back(&prmtrs->env_head, env_lstnew(env_split("B=100"), 0));
	print_export_declare_x(prmtrs->env_head, 1);


	// Printf list without adding elements in env:
	printf("-------------- EXPORT ENV AFTER ADDING  -----------------\n");
	printf("-------------- EXPORT ENV AFTER ADDING  -----------------\n");
	printf("-------------- EXPORT ENV AFTER ADDING  -----------------\n");
	printf("-------------- EXPORT ENV AFTER ADDING  -----------------\n");
	printf("-------------- EXPORT ENV AFTER ADDING  -----------------\n\n");
	char **cmnd_words;
	cmnd_words = (char **)malloc(sizeof(char *) * 6);

	// example 1
	cmnd_words[0] = ft_strdup("export\0");
	cmnd_words[1] = ft_strdup("A=1\0");
	cmnd_words[2] = ft_strdup("B\0");
	cmnd_words[3] = NULL;
	cmnd_words[4] = NULL;
	cmnd_words[5] = NULL;

//	 // example 2
//	 cmnd_words[0] = ft_strdup("export\0");
//	 cmnd_words[1] = ft_strdup("A=0\0");
//	 cmnd_words[2] = ft_strdup("B=\0");
//	 cmnd_words[3] = ft_strdup("C\0");
//	 cmnd_words[4] = NULL;
//	 cmnd_words[5] = NULL;

//	 // example 3
//	 cmnd_words[0] = ft_strdup("export\0");
//	 cmnd_words[1] = ft_strdup("A=0\0");
//	 cmnd_words[2] = NULL;
//	 cmnd_words[3] = NULL;
//	 cmnd_words[4] = NULL;
//	 cmnd_words[5] = NULL;

//	 // example 4
//	 cmnd_words[0] = ft_strdup("export\0");
//	 cmnd_words[1] = ft_strdup("AbC=0\0");
//	 cmnd_words[2] = ft_strdup("ABC=0\0");
//	 cmnd_words[3] = ft_strdup("a=0\0");
//	 cmnd_words[4] = ft_strdup("ac=0\0");
//	 cmnd_words[5] = NULL;

	builtin_export(cmnd_words, &prmtrs->env_head, 1);
	print_export_declare_x(prmtrs->env_head, 1);

	ft_free_str_arr(&cmnd_words);
	return ;
}