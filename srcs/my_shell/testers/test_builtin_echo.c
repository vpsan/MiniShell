/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_builtin_echo.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 18:30:45 by bhatches          #+#    #+#             */
/*   Updated: 2021/06/19 13:39:10 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_shell.h"

void 		test_builtin_echo(void)
{
	char **cmnd_words;
	cmnd_words = (char **)malloc(sizeof(char *) * 5);

	// example 0
	cmnd_words[0] = ft_strdup("echo\0");
	cmnd_words[1] = ft_strdup("-nnnn\0");
	cmnd_words[2] = NULL;
	cmnd_words[3] = NULL;
	cmnd_words[4] = NULL;

//	// example 1
//	cmnd_words[0] = ft_strdup("echo\0");
//	cmnd_words[1] = ft_strdup("HELLO\0");
//	cmnd_words[2] = NULL;
//	cmnd_words[3] = NULL;
//	cmnd_words[4] = NULL;

//	// example 2
//	cmnd_words[0] = ft_strdup("echo\0");
//	cmnd_words[1] = ft_strdup("HELLO\0");
//	cmnd_words[2] = ft_strdup("NAME\0");
//	cmnd_words[3] = NULL;
//	cmnd_words[4] = NULL;

//	// example 3
//	cmnd_words[0] = ft_strdup("echo\0");
//	cmnd_words[1] = ft_strdup("-nnnn\0");
//	cmnd_words[2] = ft_strdup("HELLO\0");
//	cmnd_words[3] = NULL;
//	cmnd_words[4] = NULL;

//	// example 4
//	cmnd_words[0] = ft_strdup("echo\0");
//	cmnd_words[1] = ft_strdup("-nnnn\0");
//	cmnd_words[2] = ft_strdup("-nnnn\0");
//	cmnd_words[3] = ft_strdup("HELLO\0");
//	cmnd_words[4] = NULL;

//	// example 5
//	cmnd_words[0] = ft_strdup("echo\0");
//	cmnd_words[1] = ft_strdup("-nnnn\0");
//	cmnd_words[2] = ft_strdup("HELLO\0");
//	cmnd_words[3] = ft_strdup("NAME\0");
//	cmnd_words[4] = NULL;

	builtin_echo(cmnd_words, 1);

	ft_free_str_arr(&cmnd_words);
	return ;
}