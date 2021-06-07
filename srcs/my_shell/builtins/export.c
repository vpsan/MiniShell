/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 20:04:06 by bhatches          #+#    #+#             */
/*   Updated: 2021/06/07 20:04:09 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_shell.c"
#include <printf.h>

//int 	print_export_declare_x(t_list *env_head)
//{
//	t_list	*tmp;
//
//	env_head = ft_lst_Sort(env_head);
//	tmp = env_head;
//	while(tmp != NULL)
//	{
////		ft_putstr_fd("declare -x ", 1);
////		ft_putstr_fd(tmp->env_arr[0], 1);
////		if (tmp->env_arr[1] != NULL)
////		{
////			ft_putstr_fd("=", 1);
////			putstr_export_fd("", 1);
////		}
////		else
////			ft_putstr_fd("=", 1);
////		ft_putstr_fd("\n", 1);
////		i++;
//		printf("declare -x ");
//		printf()
//		tmp = tmp->next;
//	}
//}

int 	export(char **cmnd_words, t_list *env_head)
{
	int	i;

	i = 1;
	if (cmnd_words[i] == NULL)
	{
//		print_export_declare_x(env_head);
		return (0);
	}

	return (0);
}
