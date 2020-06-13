# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmustach <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/03 19:44:11 by nmustach          #+#    #+#              #
#    Updated: 2020/04/02 22:26:10 by nmustach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../checker

FLAGS = -Wall -Wextra -Werror

PFTPATH = ../ft_printf/ -lftprintf

LFTPATH = ../ft_printf/libft -lft

CHECKERSRC = debug.c ft_atoi_validate.c main.c read_instructions.c stack_functions.c \
push_values_to_stack.c stack_functions2.c

OBJ = $(CHECKERSRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo 'Linking Checker... '
	@gcc $(FLAGS) -o $(NAME) $(OBJ) -L $(PFTPATH) -L $(LFTPATH)
	@echo 'DONE'

%.o : %.c checker.h
	@gcc $(FLAGS) -c $< -o $@
	@echo 'Compile $<'

clean:
		@echo 'rm checker object files..'
		@rm -f $(OBJ)
		@echo 'DONE'

fclean:
		@echo 'rm checker object files & executable..'
		@rm -f $(OBJ)
		@rm -f $(NAME)
		@echo 'DONE'

re: fclean all