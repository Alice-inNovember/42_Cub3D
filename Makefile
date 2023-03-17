#NAME
NAME		=	cub3D
#CMDS
CC			=	cc
RM			=	rm -rf
LIBC		=	ar rcs
#FLAGS
CFLAGS		=	-Wall -Wextra -Werror
MLXFLAGS	=	-framework OpenGL -framework AppKit
#DIRS
INCS_DIR	=	incs
SRCS_DIR	=	srcs
OBJS_DIR	=	objs
LIBS_DIR	=	libs
#FILES
SRCS		=	$(SRCS_DIR)/main.c \
				$(SRCS_DIR)/util1.c \
				$(SRCS_DIR)/util2.c \
				$(SRCS_DIR)/init_input.c \
				$(SRCS_DIR)/init_map.c \
				$(SRCS_DIR)/map_vaildity.c \
				$(SRCS_DIR)/find_minimap.c \
				$(SRCS_DIR)/mini_insert.c \
				$(SRCS_DIR)/mini_obj_insert.c \
				$(SRCS_DIR)/minimap.c

OBJFILES	=	$(SRCS:.c=.o)
OBJS	 	=	$(subst $(SRCS_DIR), $(OBJS_DIR), $(OBJFILES))
LIBGNL		=	$(LIBS_DIR)/GNL/LIBGNL.a
LIBMLX		=	$(LIBS_DIR)/MLX/libmlx.dylib

all : $(NAME)

$(NAME) : $(OBJS)
	$(MAKE) -C $(LIBS_DIR)/GNL
	$(MAKE) -C $(LIBS_DIR)/MLX
	$(CC) $(CFLAGS) -o $@ $^ $(LIBGNL) $(MLXFLAGS) -L$(LIBS_DIR)/MLX -lmlx
	-install_name_tool -change libmlx.dylib ./$(LIBMLX) $(NAME)

$(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

clean :
	$(MAKE) -C $(LIBS_DIR)/GNL clean
	$(MAKE) -C $(LIBS_DIR)/MLX clean
	$(RM) $(OBJS_DIR)

fclean : clean
	$(MAKE) -C $(LIBS_DIR)/GNL fclean
	$(MAKE) -C $(LIBS_DIR)/MLX fclean
	$(RM) $(NAME)

re :
	$(MAKE) fclean
	$(MAKE) all

.PHONY : all clean fclean re