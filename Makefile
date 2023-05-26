# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/15 13:45:13 by junlee2           #+#    #+#              #
#    Updated: 2023/05/26 15:54:00 by junlee2          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME = _vanilla
BNAME = _bonus

all : $(NAME) | Vanilla

bonus : $(BNAME) | Bonus

$(NAME) :
	@$(MAKE) -C Vanilla

$(BNAME) :
	@$(MAKE) -C Bonus

clean :
	@$(MAKE) clean -C Vanilla
	@$(MAKE) clean -C Bonus

fclean :
	@$(MAKE) fclean -C Vanilla
	@$(MAKE) fclean -C Bonus
	@rm -rf cub3D

re :
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY : all clean fclean re