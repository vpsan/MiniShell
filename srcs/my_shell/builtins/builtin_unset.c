/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 16:03:58 by bhatches          #+#    #+#             */
/*   Updated: 2021/06/19 13:24:26 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_shell.h"

int	count_words_in_arr(char **arr)
{
	int	i;

	i = 0;
	while (*arr != NULL)
	{
		arr++;
		i++;
	}
	return (i);
}

t_env_list	*creat_env_head_copy(t_env_list *env_head)
{
	t_env_list	*new_env_head;
	char		**new_arr;
	int			n_words;

	n_words = count_words_in_arr(env_head->env_arr);
	new_arr = (char **)malloc(sizeof(char *) * (n_words + 1));
	new_arr[n_words] = NULL;
	if (n_words == 1)
		new_arr[0] = ft_strdup(env_head->env_arr[0]);
	else
	{
		new_arr[0] = ft_strdup(env_head->env_arr[0]);
		new_arr[1] = ft_strdup(env_head->env_arr[1]);
	}
	new_env_head = env_lstnew(new_arr, env_head->declare_flag);
	new_env_head->next = env_head->next;
	return (new_env_head);
}

void	unset_delete_lst_element(char *s, t_env_list **env_head)
{
	t_env_list	*tmp;
	t_env_list	*previous;
	int			first_iter;

	tmp = *env_head;
	first_iter = 0;
	while (tmp != NULL)
	{
		if (ft_strcmp(s, tmp->env_arr[0]) == 0) // если нашли нужный элемент
		{
			if (first_iter == 0) // если нужно удалить первый элемент, то удаляем его, создавая новый элемент из следующего и меняем адрес листа env_head
			{
				*env_head = creat_env_head_copy(tmp->next);
				env_lstdelone(tmp->next, ft_free_str_arr);
			}
			else // если это не первый элемент - просто сдвигаем указатели, пропуская лист, который нужно удалить
				previous->next = tmp->next;
			env_lstdelone(tmp, ft_free_str_arr); // удаляем нужный лист
			break ;
		}
		previous = tmp;
		tmp = tmp->next;
		first_iter++;
	}
	return ;
}

int	check_word(char *s)
{
	int	i;

	if (ft_isdigit(s[0]) == true)
		return (ERROR);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '-' || s[i] == '=')
			return (ERROR);
		i++;
	}
	return (0);
}

int	builtin_unset(char **cmnd_words, t_env_list **env_head)
{
	int	i;

	i = 1;
	while (cmnd_words[i] != NULL) // если есть хотя бы первый аргумент, то есть строчка состоит не только из слова unset, а из (unset первый_аргумент второй_аргумент ...) 
	{
		if (check_word(cmnd_words[i]) == ERROR) // если такой аргмуент нельзя удалить, то выводи ошибки
		{
			ft_putstr_fd("my_shell: unset: '", 2);
			ft_putstr_fd(cmnd_words[i], 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
			// ТУТ У ПАРНЕЙ ОБЫЧНО EXIT_SATUS прописывается или можно вернуть ошибку
		}
		else
			unset_delete_lst_element(cmnd_words[i], env_head); // удаляем элемент из листа
		i++;
	}
	return (0);
}
