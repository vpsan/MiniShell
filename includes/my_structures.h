/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_structures.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 15:27:26 by bhatches          #+#    #+#             */
/*   Updated: 2021/06/08 16:12:26 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_STUCTURES_H
# define MY_STUCTURES_H

// # include "libft.h"

typedef struct  s_prsng
{

}               t_prsng;

typedef struct  s_cmd
{
	char 	*cmnd_str;
	char 	**cmnd_words;
//	t_flag	flgs;
//	file
//	input and output of	cmd;
}               t_cmd;

typedef struct  s_shell
{

}               t_shell;

typedef struct      s_env_list
{
	char			**env_arr;
	int				declare_flag;
	struct s_env_list	*next;
}					t_env_list;

typedef struct  s_main
{
	t_env_list		*env_head;
	char 		*input;
	t_prsng		prsng;
	t_cmd		*cmnds;
	t_shell		shell;
}               t_main;

#endif
