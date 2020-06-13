# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmustach <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/06 19:06:34 by nmustach          #+#    #+#              #
#    Updated: 2020/03/25 22:33:15 by nmustach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHK = checker_dir/
PUSHSW = push_swap_dir/
PFT = ft_printf/

all:
	@make -s -C $(PFT)
	@make -C $(CHK)
	@make -C $(PUSHSW)

clean:
	@make -s -C $(CHK) clean
	@make -C $(PUSHSW) clean
	@make -C $(PFT) clean
	
fclean:
	@make -s -C $(CHK) fclean
	@make -C $(PUSHSW) fclean
	@make -C $(PFT) fclean
	
re: fclean all