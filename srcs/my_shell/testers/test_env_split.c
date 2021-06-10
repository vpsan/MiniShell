/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_env_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 14:07:39 by bhatches          #+#    #+#             */
/*   Updated: 2021/06/10 14:07:42 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_shell.h"

void 	test_env_split(t_main prmtrs)
{
	char *s = ft_strdup("123Aaaaa===1234");
	char **arr = env_split(s);

	int i = 0;
	while (arr[i] != NULL)
	{
		printf("|%s|\n", arr[i]);
		i++;
	}
	printf("----\n");
	ft_free_str(&s);
	ft_free_str_arr(&arr);
	return ;
}
