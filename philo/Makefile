# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rferrero <rferrero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/17 11:06:31 by rferrero          #+#    #+#              #
#    Updated: 2023/06/23 16:49:18 by rferrero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					=				philos

CC						=				cc
CCFLAGS					=				-Wall -Werror -Wextra

LIB						=				-lpthread

RM						=				rm -rf

SRC						=				philosophers.c \
										$(addprefix utils/, ft_arg_check.c \
															ft_dead.c \
															ft_free.c \
															ft_init.c \
															ft_numbers.c \
															ft_print.c \
															ft_routine.c \
															ft_thread.c \
															ft_time.c)

OBJ						=				$(SRC:%.c=%.o)

all:					$(NAME)

$(NAME):				$(OBJ)
						$(CC) $(CCFLAGS) $(LIB) $(OBJ) -o $(NAME)

clean:
						$(RM) $(OBJ)

fclean:					clean
						$(RM) $(NAME)

re:						fclean all

.PHONY:					all clean fclean re