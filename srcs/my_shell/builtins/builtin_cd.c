/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 15:40:20 by bhatches          #+#    #+#             */
/*   Updated: 2021/06/09 13:26:35 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_shell.h"

int 	builtin_cd(char **cmnd_words, t_env_list* env_head)
{
	int		i;
	char	*saved_old_pwd;
	char	*saved_new_pwd;
	char	*path_to_dir;

	//////////////
	saved_old_pwd = getcwd(NULL, 0);
	if (saved_old_pwd == NULL)
	{
		ft_putstr_fd("my_shell: error retrieving current directory: getcwd: cannot access parent directories: ", 2);
		ft_putendl_fd(strerror(errno), 2);
		return (0);
	}
	///////////////
	if (cmnd_words[1] == NULL)
		path_to_dir = getvalue_env_lst("HOME", env_head);
	else
		path_to_dir = ft_strdup(cmnd_words[1]);
	///////////////
	if (chdir(path_to_dir) < 0)
	{
		ft_putstr_fd("my_shell: cd: ", 2);
		ft_putstr_fd(path_to_dir, 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(strerror(errno), 2);
		return (ERROR);
	}
	////////////////
	saved_new_pwd = getcwd(NULL, 0);
	if (saved_new_pwd == NULL)
	{
		ft_putstr_fd("my_shell: error retrieving current directory: getcwd: cannot access parent directories: ", 2);
		ft_putendl_fd(strerror(errno), 2);
		return (0);
	}
	////////////////
	updatevalue_env_lst("OLWDPWD", saved_old_pwd, &env_head);
	updatevalue_env_lst("PWD", saved_new_pwd, &env_head);
	return (0);
}
