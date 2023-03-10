#NAME
NAME		=	cub3D
#CMDS
CC			=	cc
RM			=	rm -rf
LIBC		=	ar rcs
#FLAGS
CFLAGS		=	-Wall -Wextra -Werror
#DIRS
INCS_DIR	=	incs
SRCS_DIR	=	srcs
OBJS_DIR	=	objs
LIBS_DIR	=	libs
#FILES
SRCS		=	${SRCS_DIR}/main.c
OBJFILES	=	${SRCS:.c=.o}
OBJS	 	=	$(subst $(SRCS_DIR), $(OBJS_DIR), $(OBJFILES))
LIBGNL		=	$(LIBS_DIR)/GNL/LIBGNL.a

all : $(NAME)

$(NAME) : $(OBJS)
	$(MAKE) -C $(LIBS_DIR)/GNL
	$(CC) $(CFLAGS) -o $@ $^

$(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

clean :
	$(RM) $(OBJS_DIR)

fclean : clean
	$(RM) $(NAME)

re :
	$(MAKE) fclean
	$(MAKE) all

.PHONY : all clean fclean re