/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 15:40:20 by bhatches          #+#    #+#             */
/*   Updated: 2021/06/08 16:12:26 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_shell.h"

//int		cd(char **cmnd_words, t_env_list *env_var)
//{
//	char	*final_path;
//	int 	i;
//
//	if (cmnd_words[1] == NULL)
//	{
//		final_path = get_env(env_var, "HOME");
//		if (final_path == NULL)
//			return (ERROR);//NO HOME in ENV
//	}
//	else
//		final_path = cmnd_words[1];
//	if (chdir(final_path) == -1)
//		return (ERROR);//NOT CORRECT final_path
//	return (0);
//}

int 	builtin_cd(char **cmnd_words)
{

	return (0);
}