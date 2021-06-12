/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 15:40:16 by bhatches          #+#    #+#             */
/*   Updated: 2021/06/09 22:50:14 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_shell.h"

int 	check_n_flag(char *str, int *flag)
{
	if (*str++ == '-')
	{
		if (*str == 'n')
		{
			while (*str != '\0')
			{
				if (*str != 'n')
					return (false);
				str++;
			}
			*flag = 1;
			return (true);
		}
	}
	return (false);
}

int 	builtin_echo(char **cmnd_words, int out_fd)
{
	int	i;
	int	flag;

	flag = 0;
	i = 1;
	while (cmnd_words[i] != '\0' && check_n_flag(cmnd_words[i], &flag) == true)
		i++;
	while (cmnd_words[i] != NULL)
	{
		ft_putstr_fd(cmnd_words[i], out_fd);
		if (cmnd_words[++i] != NULL)
			ft_putstr_fd(" ", out_fd);
	}
	if (flag != 1)
		ft_putstr_fd("\n", out_fd);
	return (0);
}
