/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 15:40:20 by bhatches          #+#    #+#             */
/*   Updated: 2021/06/19 13:45:06 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_shell.h"

int 	print_errno_getcwd(int return_value)
{
	ft_putstr_fd("my_shell: error retrieving current directory: \
				 getcwd: cannot access parent directories: ", 2);
	ft_putendl_fd(strerror(errno), 2);//errno
	return (return_value);
}

int 	print_errno_path(char *str, int return_value)
{
	ft_putstr_fd("my_shell: cd: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(strerror(errno), 2);//errno
	return (return_value);
}

int 	builtin_cd(char **cmnd_words, t_env_list *env_head)
{
	char	*saved_old_pwd;
	char	*saved_new_pwd;
	char	*path_to_dir;

	saved_old_pwd = getcwd(NULL, 0); // сохраняем старый pwd
	if (saved_old_pwd == NULL)
		print_errno_getcwd(0);//maybe it is better to return ERROR which is defined (-1)
	if (cmnd_words[1] == NULL)
		path_to_dir = getvalue_env_lst("HOME", env_head); // если написали "cd" без аргументов, вернуться в home
	else
		path_to_dir = ft_strdup(cmnd_words[1]); // если написали "cd аргумент", пойти в аргумент
	if (chdir(path_to_dir) < 0) // переходим в в директорию "path_to_dir"
		return (print_errno_path(path_to_dir, ERROR));
	saved_new_pwd = getcwd(NULL, 0); // сохраняем новый pwd
	if (saved_new_pwd == NULL)
		print_errno_getcwd(0);
	if (saved_old_pwd != NULL)
		updatevalue_env_lst("OLDPWD", saved_old_pwd, &env_head); // обновляем старый pwd
	if (saved_new_pwd != NULL)
		updatevalue_env_lst("PWD", saved_new_pwd, &env_head);// обновляем новый pwd
	ft_free_str(&path_to_dir);
	return (0);
}
