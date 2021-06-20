/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_structures.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 12:30:27 by bhatches          #+#    #+#             */
/*   Updated: 2021/06/19 14:05:29 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_STUCTURES_H
# define MY_STUCTURES_H

typedef struct			s_prsng
{

}						t_prsng;

typedef struct			s_cmd
{
	char				*cmnd_str;
	char				**cmnd_words;
//	flgs;
//	files
//	input and output of	cmd;
}						t_cmd;

typedef struct			s_shell
{

}						t_shell;

typedef struct			s_env_list
{
	char				**env_arr;//name=value; env_arr[0] -> name.  env_arr[1] -> value. 
	int					declare_flag; // declare_flag = 1 если value существует.
	struct s_env_list	*next;
}						t_env_list;

typedef struct  		s_main
{
	t_env_list			*env_head;
	char				*input;
	t_prsng				prsng;
	t_cmd				**cmnds;
	t_shell				shell;
}						t_main;

#endif
