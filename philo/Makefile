# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/17 11:06:31 by rferrero          #+#    #+#              #
#    Updated: 2023/05/20 23:17:23 by rferrero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					=				philos

CC						=				cc
CCFLAGS					=				-Wall -Werror -Wextra

LIB						=				-lpthread

RM						=				rm -rf

SRC						=				philosophers.c \
										$(addprefix utils/, ft_arg_check.c \
															ft_free.c \
															ft_init.c \
															ft_loop.c \
															ft_numbers.c \
															ft_print.c)

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