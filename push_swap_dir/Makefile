# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmustach <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/03 19:44:11 by nmustach          #+#    #+#              #
#    Updated: 2020/04/02 22:29:07 by nmustach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../push_swap

FLAGS = -Wall -Wextra -Werror

CHKDIR = ../checker_dir/

PFTPATH = ../ft_printf/ -lftprintf

LFTPATH = ../ft_printf/libft -lft

CHKSRC = $(CHKDIR)debug.o $(CHKDIR)ft_atoi_validate.o $(CHKDIR)read_instructions.o $(CHKDIR)stack_functions.o \
$(CHKDIR)push_values_to_stack.o $(CHKDIR)stack_functions2.o

PUSHSWSRC = push_swap_main.c stacklen.c sort.c sequence.c calc_funcs.c get_min_funcs.c utils.c under_5_funcs.c

OBJ = $(PUSHSWSRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(CHKSRC)
	@echo 'Linking Push_Swap... '
	@gcc $(OBJ) $(CHKSRC) $(FLAGS) -o $(NAME) -L $(PFTPATH) -L $(LFTPATH)
	@echo 'DONE'
	
%.o : %.c push_swap.h $(CHKDIR)checker.h
	@gcc $(FLAGS) -c $< -o $@
	@echo 'Compile $<'

clean:
		@echo 'rm push_swap object files..'
		@rm -f $(OBJ)
		@echo 'DONE'

fclean:
		@echo 'rm push_swap object files & executable..'
		@rm -f $(OBJ)
		@rm -f $(NAME)
		@echo 'DONE'	
		
re: fclean all
