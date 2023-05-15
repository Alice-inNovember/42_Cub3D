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