/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_structures.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 12:30:27 by bhatches          #+#    #+#             */
/*   Updated: 2021/09/17 01:40:55 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_STRUCTURES_H
# define MY_STRUCTURES_H

# include <stdbool.h>
# include <stdio.h>
# define NOT_EXECUTE 1
# define EXECUTE 3
# define ERROR -1
# define SUCCESSFUL_EXIT 0
# define DONT_CLEAN_ENV 100
# define STDIN 0
# define STDOUT 1
# define SRDERR 2

/*
 * DESCRIPTION s_cmd_list
 * orig_cmnd_str 	<-> comand
 * copy_cmnd_str 	<-> comand
 * cmnd_words 		<-> arr of arr[0] = comand and its arguments
 * before_redirect 	<-> comand str before redirect
 * after_redirect 	<-> comand str after redirect
 * is_builtin		<-> true/false flag
 * is_double_r		<-> true/false flag
 * is_double_l		<-> true/false flag
 * is_single_r		<-> true/false flag
 * is_single_l		<-> true/false flag
 * is_pipe			<-> true/false flag
 * fd_in			<-> file descriptor
 * fd_out			<-> file descriptor
*/

typedef struct s_cmd_list
{
	char				*orig_cmnd_str;
	char				*copy_cmnd_str;
	char				**cmnd_words;
	char				*before_redirect;
	char				*after_redirect;
	bool				is_builtin;
	bool				is_double_r;
	bool				is_double_l;
	bool				is_single_r;
	bool				is_single_l;
	bool				is_pipe;		
	int					fd_in;			
	int					fd_out;	
	struct s_cmd_list	*next;
}						t_cmd_list;

/*
 * DESCRIPTION t_env_list
 * If env looks like name=value, than:
 * env_arr[0] 	<-> name
 * env_arr[1] 	<-> value
 * declare_flag  = 	1 if value exist
 * declare_flag  = 	0 if value doesnt exist
*/

typedef struct s_env_list
{
	char				**env_arr;
	int					declare_flag;
	struct s_env_list	*next;
}						t_env_list;

/*
 * DESCRIPTION t_main
 * env_head 			<-> env list
 * cmd_head 			<-> comand list
 * nb_pipes 			<-> number of pipes in command line
 * orig_line_input 		<-> readline()
 * copy_line_input 		<-> readline() copy if needed
*/

typedef struct s_main
{
	t_env_list			*env_head;
	t_cmd_list			*cmd_head;
	char				*orig_line_input;
	char				*copy_line_input;
	int					nb_pipes;
	int					fd_output;
	int					exit_status;
}						t_main;

#endif
