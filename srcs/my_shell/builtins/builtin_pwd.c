/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 15:40:18 by bhatches          #+#    #+#             */
/*   Updated: 2021/06/19 12:10:59 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_shell.h"

int	builtin_pwd(int out_fd)
{
	char	*pwd_str;

	pwd_str = getcwd(NULL, 0);// getcwd возвращает в pwd_str замолоченную pwd 
	if (pwd_str == NULL)
	{
		ft_putstr_fd("error retrieving current directory: getcwd: cannot \
				access parent directories: No such file or directory", 2);
		ft_putendl_fd(strerror(errno), 2);//errno
		return (ERROR);
	}
	ft_putendl_fd(pwd_str, out_fd);// выводим pwd_str в out_fd
	free(pwd_str);// очищаем замолеченную строку pwd_str
	return (0);
}
