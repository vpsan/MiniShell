# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/08 17:52:23 by bhatches          #+#    #+#              #
#    Updated: 2021/05/31 15:27:05 by bhatches         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRCS	=	$(MAIN)				\
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

LIBFT_DIR 	= srcs/libft/
LIBFT 		= $(LIBFT_DIR)libft.a

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
MY_SHELL			= 	$(MY_SHELL_DIR)my_shell.c\
						$(MY_SHELL_DIR)builtins/pwd.c\
						$(MY_SHELL_DIR)builtins/echo.c\
#						$(MY_SHELL_DIR)your_function_2.c\
#						etc

# ***************************************************************************** #



OBJ		=	$(SRCS:.c=.o)

CC		=	gcc

#CFLAGS	=	-Wall -Wextra -Werror -g
CFLAGS	=	-g
OPTFLGS	=	-O2

all:		$(NAME)

$(NAME):	$(OBJ)
			make -C $(LIBFT_DIR)
			$(CC) $(CFLAGS) $(LIBFT) $(OBJ) -o $(NAME)
.c.o:
			@$(CC) $(CFLAGS) -I$(INCLD) -c $< -o $(<:.c=.o)

clean:
			make clean -C $(LIBFT_DIR)
			@rm -rf $(OBJ)

fclean:		clean
			make fclean -C $(LIBFT_DIR)
			@rm -rf $(NAME)

re:			fclean all
