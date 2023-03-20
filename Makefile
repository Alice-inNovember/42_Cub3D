#NAME
NAME			=	cub3D
#CMDS
CC				=	cc
RM				=	rm -rf
LIBC			=	ar rcs
#FLAGS
CFLAGS			=	-Wall -Wextra -Werror
MLXFLAGS		=	-framework OpenGL -framework AppKit
#DIRS	
INCS_DIR		=	incs
SRCS_DIR		=	srcs
GM_PLAY_DIR		=	$(SRCS_DIR)/gameplay
INITIAL_DIR		=	$(SRCS_DIR)/initial
MINIMAP_DIR		=	$(SRCS_DIR)/minimap
UTILITY_DIR		=	$(SRCS_DIR)/utility
OBJS_DIR		=	objs
GM_PLAY_OBJ		=	$(OBJS_DIR)/gameplay
INITIAL_OBJ		=	$(OBJS_DIR)/initial
MINIMAP_OBJ		=	$(OBJS_DIR)/minimap
UTILITY_OBJ		=	$(OBJS_DIR)/utility
LIBS_DIR		=	libs
#FILES
MAIN_SRCS		=	$(SRCS_DIR)/main.c \
					$(GM_PLAY_DIR)/player_controll.c \
					$(GM_PLAY_DIR)/renderer.c \
					$(INITIAL_DIR)/init_event.c \
					$(INITIAL_DIR)/init_input.c \
					$(INITIAL_DIR)/init_libx.c \
					$(INITIAL_DIR)/init_map.c \
					$(INITIAL_DIR)/init_texture.c \
					$(MINIMAP_DIR)/find_minimap.c \
					$(MINIMAP_DIR)/mini_insert.c \
					$(MINIMAP_DIR)/mini_obj_insert.c \
					$(MINIMAP_DIR)/minimap.c \
					$(UTILITY_DIR)/colors.c\
					$(UTILITY_DIR)/map_vaildity.c \
					$(UTILITY_DIR)/util1.c \
					$(UTILITY_DIR)/util2.c
MAIN_OBJ		=	$(MAIN_SRCS:.c=.o)
OBJS			=	$(subst $(SRCS_DIR), $(OBJS_DIR), $(MAIN_OBJ))
LIBGNL			=	$(LIBS_DIR)/GNL/LIBGNL.a
LIBMLX			=	$(LIBS_DIR)/MLX/libmlx.dylib

all : $(NAME)

$(NAME) : $(OBJS)
	$(MAKE) -C $(LIBS_DIR)/GNL
	$(MAKE) -C $(LIBS_DIR)/MLX
	$(CC) $(CFLAGS) -o $@ $^ $(LIBGNL) $(MLXFLAGS) -L$(LIBS_DIR)/MLX -lmlx
	-install_name_tool -change libmlx.dylib ./$(LIBMLX) $(NAME)

$(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
$(GM_PLAY_OBJ)/%.o : $(GM_PLAY_DIR)/%.c | $(GM_PLAY_OBJ)
	$(CC) $(CFLAGS) -c $< -o $@
$(INITIAL_OBJ)/%.o : $(INITIAL_DIR)/%.c | $(INITIAL_OBJ)
	$(CC) $(CFLAGS) -c $< -o $@
$(MINIMAP_OBJ)/%.o : $(MINIMAP_DIR)/%.c | $(MINIMAP_OBJ)
	$(CC) $(CFLAGS) -c $< -o $@
$(UTILITY_OBJ)/%.o : $(UTILITY_DIR)/%.c | $(UTILITY_OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)
	mkdir -p $(GM_PLAY_OBJ)
	mkdir -p $(INITIAL_OBJ)
	mkdir -p $(MINIMAP_OBJ)
	mkdir -p $(UTILITY_OBJ)

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