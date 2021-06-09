/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf_all_env_lst.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 20:05:12 by bhatches          #+#    #+#             */
/*   Updated: 2021/06/08 16:12:26 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_shell.h"
#include "libft.h"
#include <printf.h>

void	test_printf_all_env_lst(t_env_list *env_head)
{
	t_env_list	*tmp;
	int		number_i;

	tmp = env_head;
	number_i = 0;
	while (tmp != NULL)
	{
		printf("name = %s\n", tmp->env_arr[0]);
		printf("value = %s\n", tmp->env_arr[1]);
		printf("declare_flag = %d\n", tmp->declare_flag);
		printf("number_i = %d\n", number_i);
		printf("\n");
		tmp = tmp->next;
		number_i++;
	}
	return ;
}
