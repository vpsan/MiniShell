/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 20:04:06 by bhatches          #+#    #+#             */
/*   Updated: 2021/06/19 13:33:17 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_shell.h"

int 	print_export_declare_x(t_env_list *env_head, int out_fd)
{
	t_env_list	*tmp;

	env_lstsort_bubble(env_head);
	tmp = env_head;
	while (tmp != NULL)
	{
		ft_putstr_fd("declare -x ", out_fd);
		ft_putstr_fd(tmp->env_arr[0], out_fd);
		if (tmp->env_arr[1] == NULL)
			ft_putstr_fd("\n", out_fd);
		else//выводим только такие элементы, у который есть значение 
		{
			ft_putstr_fd("=\"", out_fd);
			ft_putstr_fd(tmp->env_arr[1], out_fd);
			ft_putstr_fd("\"\n", out_fd);
		}
		tmp = tmp->next;
	}
	return (0);
}

int 	builtin_export(char **cmnd_words, t_env_list **env_head, int out_fd)
{
	char	**arr;
	int		i;
	char	*name;

	if (cmnd_words[1] == NULL) // если первого аргумента нет, то есть строчка состоит  только из слова export
		return (print_export_declare_x(*env_head, out_fd)); // выводим отсортированный лист
	else
	{// если в лист нужно добавить слово
		i = 1;
		while (cmnd_words[i] != NULL)//идем по всем аргументам-словам, которые нужно добавить. Каждый i-й аргумент имеет вид name=value
		{
			name = ft_strdup_sep(cmnd_words[i], '=');// получаем name
			if (check_env_name_exists(name, *env_head) == true)// проверяем, есть ли name в списке. Если такой элемент уже есть, то удаляем его. Чтобы потом создать новый name с обновленным значением. 
				unset_delete_lst_element(name, env_head);// удаляем элемент с именем name.
			ft_free_str(&name);
			arr = env_split(cmnd_words[i]);// из i-го аргумента name=value получаем arr[0] = name, arr[1] = value
			if (arr[1] == NULL)// если value  не был передан, то добавляем элмент с флагом 0.
				env_lstadd_back(env_head, env_lstnew(arr, 0));
			else// если value="\0" или value="string", то добавляем элмент с флагом 1.
				env_lstadd_back(env_head, env_lstnew(arr, 1));
			i++;
		}
	}
	return (0);
}
