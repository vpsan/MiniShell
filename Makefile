# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/08 17:52:23 by bhatches          #+#    #+#              #
#    Updated: 2021/09/17 09:40:43 by bhatches         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRCS	=	$(MAIN)				\
			$(LIB)				\
			$(GET_NEXT_LINE)	\
			$(PRSNG_VLDTN)		\
			$(MY_SHELL)			\


# *********************** MAIN ************************************************ #

MAIN_DIR 	= 	srcs/
MAIN		= 	$(MAIN_DIR)main.c

# *********************** HDRS ************************************************ #

INCLD 	= 	includes/
HDRS	=	$(INCLD)libft.h\
			$(INCLD)get_next_line.h\
			$(INCLD)my_structures.h\
			$(INCLD)prsng_vldtn.h\
			$(INCLD)my_shell.h\

# *********************** LIBFT *********************************************** #	

LIBFT_DIR 	= srcs/libft/
LIBFT 		= $(LIBFT_DIR)libft.a

# *********************** GET_NEXT_LINE *************************************** #

GET_NEXT_LINE_DIR 	= 	srcs/get_next_line/
GET_NEXT_LINE		= 	$(GET_NEXT_LINE_DIR)get_next_line.c\
						$(GET_NEXT_LINE_DIR)get_next_line_utils.c\

# *********************** PRSNG_VLDTN ***************************************** #

PRSNG_VLDTN_DIR		= 	srcs/prsng_vldtn/
PRSNG_VLDTN			=	$(PRSNG_VLDTN_DIR)prsng_vldtn.c\
						$(PRSNG_VLDTN_DIR)check_input.c\
						$(PRSNG_VLDTN_DIR)check_pipe.c\
						$(PRSNG_VLDTN_DIR)check_redirect.c\
						$(PRSNG_VLDTN_DIR)look_quotes.c\
						$(PRSNG_VLDTN_DIR)ft_isspace.c\
						$(PRSNG_VLDTN_DIR)find_redirect.c\
						$(PRSNG_VLDTN_DIR)handle_quotes.c\
						$(PRSNG_VLDTN_DIR)len_of_array.c \
						$(PRSNG_VLDTN_DIR)len_of_str.c\
						$(PRSNG_VLDTN_DIR)find_dollar.c\
						$(PRSNG_VLDTN_DIR)find_builtin.c\
						$(PRSNG_VLDTN_DIR)double_r_redirect.c\
						$(PRSNG_VLDTN_DIR)double_l_redirect.c\
						$(PRSNG_VLDTN_DIR)single_l_redirect.c\
						$(PRSNG_VLDTN_DIR)single_r_redirect.c\
						$(PRSNG_VLDTN_DIR)single_r_fd.c \
						$(PRSNG_VLDTN_DIR)single_l_fd.c\
						$(PRSNG_VLDTN_DIR)double_l_fd.c\
						$(PRSNG_VLDTN_DIR)double_r_fd.c\
						$(PRSNG_VLDTN_DIR)creat_cmd_list.c\
						$(PRSNG_VLDTN_DIR)delete_spaces.c\
						$(PRSNG_VLDTN_DIR)before_redirect.c\
						$(PRSNG_VLDTN_DIR)after_redirect.c\
						$(PRSNG_VLDTN_DIR)af_alnum.c\
						$(PRSNG_VLDTN_DIR)af_quotes.c\
						$(PRSNG_VLDTN_DIR)af_quote.c\
						$(PRSNG_VLDTN_DIR)be_alnum.c\
						$(PRSNG_VLDTN_DIR)be_quotes.c\
						$(PRSNG_VLDTN_DIR)be_quote.c\
						$(PRSNG_VLDTN_DIR)make_str.c\
						$(PRSNG_VLDTN_DIR)routine.c\
						$(PRSNG_VLDTN_DIR)dollar.c\
						$(PRSNG_VLDTN_DIR)serch.c\
						$(PRSNG_VLDTN_DIR)skip_space.c\
						$(PRSNG_VLDTN_DIR)quote.c\
						$(PRSNG_VLDTN_DIR)quotes.c\
						$(PRSNG_VLDTN_DIR)al_num.c\
						$(PRSNG_VLDTN_DIR)setup_terminal.c\
						$(PRSNG_VLDTN_DIR)sigint_handler.c\
						$(PRSNG_VLDTN_DIR)check_line.c\

# *********************** MY_SHELL ******************************************** #

MY_SHELL_DIR		= 	srcs/my_shell/
ENV					=	$(MY_SHELL_DIR)0_env/
MANAGER				=	$(MY_SHELL_DIR)1_shell_manager/
BUILTINS_DIR		=	$(MY_SHELL_DIR)2_builtins/
EXECUTE_EXECVE		=	$(MY_SHELL_DIR)3_execute_execve/
TESTERS				=	$(MY_SHELL_DIR)4_testers/


MY_SHELL			= 	$(MY_SHELL_DIR)my_shell.c\
						\
						$(ENV)create_env_lst.c\
						$(ENV)env_lstsort_bubble.c\
                        $(ENV)env_lstnew.c\
                        $(ENV)env_lstadd_front.c\
                        $(ENV)env_lstdelone.c\
                        $(ENV)env_lstsize.c \
                        $(ENV)env_lstlast.c \
                        $(ENV)env_lstadd_back.c\
                        $(ENV)env_lstclear.c\
                        $(ENV)env_lstiter.c\
                        $(ENV)env_lstmap.c\
                        $(ENV)getvalue_env_lst.c\
                        $(ENV)updatevalue_env_lst.c\
                        $(ENV)env_split.c\
                        $(ENV)check_env_name_exists.c\
                        $(ENV)env_create_arr.c\
						\
                        $(MANAGER)my_shell_execute.c\
                        $(MANAGER)pipe_execve_or_builtins.c\
                        $(MANAGER)redirect_cmd_fd.c\
                        $(MANAGER)create_pipe.c\
                        $(MANAGER)free_utils.c\
                        \
                        $(BUILTINS_DIR)builtin_env.c\
                        $(BUILTINS_DIR)builtin_unset.c\
                        $(BUILTINS_DIR)builtin_export.c\
						$(BUILTINS_DIR)builtin_pwd.c\
						$(BUILTINS_DIR)builtin_echo.c\
						$(BUILTINS_DIR)builtin_cd.c\
						$(BUILTINS_DIR)builtin_exit.c\
						$(BUILTINS_DIR)builtins.c\
                        \
                        $(EXECUTE_EXECVE)execute_execve.c\

# ***************************************************************************** #


OBJ		=	$(SRCS:.c=.o)

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -g

READLINELFLAGS	=	-L/Users/$(USER)/.brew/Cellar/readline/8.0.4/lib -lreadline

all:		$(NAME)

$(NAME):	$(OBJ)
			make -C $(LIBFT_DIR)
			$(CC) $(CFLAGS) $(LIBFT) $(READLINELFLAGS) $(OBJ) -o $(NAME)

.c.o:
			@$(CC) $(CFLAGS) -I$(INCLD) -c $< -o $(<:.c=.o)

clean:
			make clean -C $(LIBFT_DIR)
			@rm -rf $(OBJ)

fclean:		clean
			make fclean -C $(LIBFT_DIR)
			@rm -rf $(NAME)

re:			fclean all

# .SILENT:	all $(NAME) .c.o clean fclean re

