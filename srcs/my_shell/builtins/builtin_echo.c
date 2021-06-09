/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 15:40:16 by bhatches          #+#    #+#             */
/*   Updated: 2021/06/09 12:03:45 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_shell.h"

/*
**	c_arg - command argument; For example in "echo -n hello",c_arg is "-n hello"
**	fd - file descriptor
*/

//int n_checker(char *cmnd_words_1)
//{
//	int i;
//	int n_count;
//
//	i = 0;
//	if (cmnd_words_1[i] != '-')
//		return (0);
//	i++;
//	n_count = 0;
//	while (cmnd_words_1[i] != '\0')
//	{
//		if (c_arg[i] == 'n')
//			n_count++;
//		i++;
//	}
//	return (n_count);
//}
//
//int	echo(char *cmnd_str, char **cmnd_words, int fd)
//{
//	int		i;
//	int 	n_count;
//
//	if (cmnd_words[1] != NULL)
//		n_count = n_checker(cmnd_words[1]);
//	if (n_count == 0)
//		write(1, "\n", 1);
//	return (0);
//}

int 	builtin_echo(char **cmnd_words)
{

	return (0);
}
