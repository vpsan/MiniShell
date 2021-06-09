# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/08 17:52:23 by bhatches          #+#    #+#              #
#    Updated: 2021/06/09 13:26:13 by bhatches         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRCS	=	$(MAIN)				\
			$(LIB)				\
			$(GET_NEXT_LINE)	\
			$(MY_ERRORS)		\
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
			$(INCLD)my_errors.h\
			$(INCLD)prsng_vldtn.h\
			$(INCLD)my_shell.h\
#			$(INCLD)your_header_1.h\
#			$(INCLD)your_header_2.h\
#			etc

# *********************** LIBFT *********************************************** #	

#LIBFT_DIR 	= srcs/libft/
#LIBFT 		= $(LIBFT_DIR)libft.a

LIBFT_DIR 	= srcs/libft/
LIB 		= 		$(LIBFT_DIR)ft_memset.c\
              $(LIBFT_DIR)ft_bzero.c\
              $(LIBFT_DIR)ft_memcpy.c\
              $(LIBFT_DIR)ft_memccpy.c\
              $(LIBFT_DIR)ft_memmove.c\
              $(LIBFT_DIR)ft_memchr.c\
              $(LIBFT_DIR)ft_memcmp.c\
              $(LIBFT_DIR)ft_strlen.c\
              $(LIBFT_DIR)ft_isalpha.c\
              $(LIBFT_DIR)ft_isdigit.c\
              $(LIBFT_DIR)ft_isalnum.c\
              $(LIBFT_DIR)ft_isascii.c\
              $(LIBFT_DIR)ft_isprint.c\
              $(LIBFT_DIR)ft_toupper.c\
              $(LIBFT_DIR)ft_tolower.c\
              $(LIBFT_DIR)ft_strrchr.c\
              $(LIBFT_DIR)ft_strchr.c\
              $(LIBFT_DIR)ft_strncmp.c\
              $(LIBFT_DIR)ft_strcmp.c\
              $(LIBFT_DIR)ft_strlcpy.c\
              $(LIBFT_DIR)ft_strlcat.c\
              $(LIBFT_DIR)ft_strnstr.c\
              $(LIBFT_DIR)ft_atoi.c\
              $(LIBFT_DIR)ft_calloc.c\
              $(LIBFT_DIR)ft_strdup.c\
              $(LIBFT_DIR)ft_putchar_fd.c\
              $(LIBFT_DIR)ft_substr.c\
              $(LIBFT_DIR)ft_strjoin.c\
              $(LIBFT_DIR)ft_strtrim.c\
              $(LIBFT_DIR)ft_putstr_fd.c\
              $(LIBFT_DIR)ft_putendl_fd.c\
              $(LIBFT_DIR)ft_putnbr_fd.c\
              $(LIBFT_DIR)ft_itoa.c\
              $(LIBFT_DIR)ft_strmapi.c\
              $(LIBFT_DIR)ft_split.c \
                  $(LIBFT_DIR)ft_lstnew.c\
              $(LIBFT_DIR)ft_lstadd_front.c\
              $(LIBFT_DIR)ft_lstdelone.c\
              $(LIBFT_DIR)ft_lstsize.c \
              $(LIBFT_DIR)ft_lstlast.c \
              $(LIBFT_DIR)ft_lstadd_back.c\
              $(LIBFT_DIR)ft_lstclear.c\
              $(LIBFT_DIR)ft_lstiter.c\
              $(LIBFT_DIR)ft_lstmap.c\
              		$(LIBFT_DIR)ft_strlen_sep.c \
              $(LIBFT_DIR)ft_free_str.c \
              $(LIBFT_DIR)ft_free_str_arr.c



# *********************** GET_NEXT_LINE *************************************** #

GET_NEXT_LINE_DIR 	= 	srcs/get_next_line/
GET_NEXT_LINE		= 	$(GET_NEXT_LINE_DIR)get_next_line.c\
						$(GET_NEXT_LINE_DIR)get_next_line_utils.c\

# *********************** MY_ERRORS ******************************************* #

MY_ERRORS_DIR 		= 	srcs/my_errors/
MY_ERRORS			= 	$(MY_ERRORS_DIR)my_errors.c
#						$(MY_ERRORS_DIR)your_function_1.c\
#						$(MY_ERRORS_DIR)your_function_2.c\
#						etc

# *********************** PRSNG_VLDTN ***************************************** #

PRSNG_VLDTN_DIR		= 	srcs/prsng_vldtn/
PRSNG_VLDTN			=	$(PRSNG_VLDTN_DIR)prsng_vldtn.c\
#						$(PRSNG_VLDTN_DIR)your_function_1.c\
#						$(PRSNG_VLDTN_DIR)your_function_2.c\
#						etc

# *********************** MY_SHELL ******************************************** #

MY_SHELL_DIR		= 	srcs/my_shell/
BUILTINS_DIR		=	$(MY_SHELL_DIR)builtins/
ENV					=	$(MY_SHELL_DIR)env/
TESTERS				=	$(MY_SHELL_DIR)testers/

MY_SHELL			= 	$(MY_SHELL_DIR)my_shell.c\
						\
                        $(BUILTINS_DIR)builtin_env.c\
                        $(BUILTINS_DIR)builtin_unset.c\
                        $(BUILTINS_DIR)builtin_export.c\
						$(BUILTINS_DIR)builtin_pwd.c\
						$(BUILTINS_DIR)builtin_echo.c\
						$(BUILTINS_DIR)builtin_cd.c\
						$(BUILTINS_DIR)builtin_exit.c\
						\
						$(ENV)create_env_lst.c\
						$(ENV)env_lst_sort.c\
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
                        \
						$(TESTERS)test_env_add.c\
                        $(TESTERS)test_printf_all_env_lst.c\
                        $(TESTERS)test_updatevalue_env_lst.c\
                        $(TESTERS)test_builtins_env.c\
                        $(TESTERS)test_builtins_unset.c\
                        $(TESTERS)test_builtins_export.c\
                        $(TESTERS)test_builtin_cd.c\
                        $(TESTERS)test_builtin_echo.c\

# ***************************************************************************** #


OBJ		=	$(SRCS:.c=.o)

CC		=	gcc

#CFLAGS	=	-Wall -Wextra -Werror -g
CFLAGS	=	-g
OPTFLGS	=	-O2

all:		$(NAME)

$(NAME):	$(OBJ)
#			make -C $(LIBFT_DIR)
			$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
#			$(CC) $(CFLAGS) $(LIBFT) $(OBJ) -o $(NAME)

.c.o:
			@$(CC) $(CFLAGS) -I$(INCLD) -c $< -o $(<:.c=.o)

clean:
#			make clean -C $(LIBFT_DIR)
			@rm -rf $(OBJ)

fclean:		clean
#			make fclean -C $(LIBFT_DIR)
			@rm -rf $(NAME)

re:			fclean all

.SILENT:	all $(NAME) .c.o clean fclean re

