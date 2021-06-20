/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 15:40:16 by bhatches          #+#    #+#             */
/*   Updated: 2021/06/19 13:42:30 by bhatches         ###   ########.fr       */
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

// короче, echo с влагом "-n" в bash работает так, что не пишет в конце слов \n. 
// и флаги могут быть написаны так: echo -n string, echo -nn -nnnnnn string.
// Но может быть написано echo -nnhello и это уже не флаг.
int 	builtin_echo(char **cmnd_words, int out_fd)
{
	int	i;
	int	flag;

	flag = 0;
	i = 1;
	while (cmnd_words[i] != '\0' && check_n_flag(cmnd_words[i], &flag) == true)// идем по аргументам и проверяем если это флаги, считаем их
		i++;
	while (cmnd_words[i] != NULL) // Если это уже не флаг 
	{
		ft_putstr_fd(cmnd_words[i], out_fd); // выводим слово 
		if (cmnd_words[++i] != NULL)
			ft_putstr_fd(" ", out_fd); // если это не последнее слово, выводи пробелы между словами
	}
	if (flag != 1)
		ft_putstr_fd("\n", out_fd); // пиши в конце \n если флага -n не было
	return (0);
}
