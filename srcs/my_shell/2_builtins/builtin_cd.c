/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 15:40:20 by bhatches          #+#    #+#             */
/*   Updated: 2021/09/17 00:04:32 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_shell.h"

int	print_errno_getcwd(char *saved_old_pwd, char *saved_new_pwd, int rtrn_value)
{
	ft_putstr_fd("my_shell: error retrieving current directory: \
				 getcwd: cannot access parent directories: ", 2);
	ft_putendl_fd(strerror(errno), 2);
	if (saved_old_pwd != NULL)
		ft_free_str(&saved_old_pwd);
	if (saved_new_pwd != NULL)
		ft_free_str(&saved_new_pwd);
	return (rtrn_value);
}

int	print_errno_path(char *path_to_dir, char *saved_old_pwd,
											t_main *prmtrs, int rtrn_value)
{
	ft_putstr_fd("my_shell: cd: ", 2);
	ft_putstr_fd(path_to_dir, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(strerror(errno), 2);
	ft_free_str(&path_to_dir);
	ft_free_str(&saved_old_pwd);
	prmtrs->exit_status = 1;
	return (rtrn_value);
}

int	builtin_cd(char **cmnd_words, t_env_list *env_head, t_main *prmtrs)
{
	char	*saved_old_pwd;
	char	*saved_new_pwd;
	char	*path_to_dir;

	saved_old_pwd = getcwd(NULL, 0);
	if (saved_old_pwd == NULL)
		return (print_errno_getcwd(saved_old_pwd, NULL, ERROR));
	if (cmnd_words[1] == NULL)
		path_to_dir = getvalue_env_lst("HOME", env_head);
	else
		path_to_dir = ft_strdup(cmnd_words[1]);
	if (chdir(path_to_dir) < 0)
		return (print_errno_path(path_to_dir, saved_old_pwd, prmtrs, ERROR));
	saved_new_pwd = getcwd(NULL, 0);
	if (saved_new_pwd == NULL)
		return (print_errno_getcwd(saved_old_pwd, saved_new_pwd, ERROR));
	if (saved_old_pwd != NULL)
		updatevalue_env_lst("OLDPWD", saved_old_pwd, &env_head);
	if (saved_new_pwd != NULL)
		updatevalue_env_lst("PWD", saved_new_pwd, &env_head);
	ft_free_str(&path_to_dir);
	return (0);
}
