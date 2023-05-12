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
INPUTDATA_DIR	=	$(SRCS_DIR)/input_data
DRAWWALLIMG_DIR	=	$(SRCS_DIR)/draw_wall_img
OBJS_DIR		=	objs
GM_PLAY_OBJ		=	$(OBJS_DIR)/gameplay
INITIAL_OBJ		=	$(OBJS_DIR)/initial
MINIMAP_OBJ		=	$(OBJS_DIR)/minimap
UTILITY_OBJ		=	$(OBJS_DIR)/utility
INPUTDATA_OBJ	=	$(OBJS_DIR)/input_data
DRAWWALLIMG_OBJ	=	$(OBJS_DIR)/draw_wall_img
LIBS_DIR		=	libs
#FILES
MAIN_SRCS		=	$(SRCS_DIR)/main.c \
					$(GM_PLAY_DIR)/hook_box.c \
					$(GM_PLAY_DIR)/key_player_move.c \
					$(GM_PLAY_DIR)/key_player_rotate.c \
					$(GM_PLAY_DIR)/mouse_set.c \
					$(GM_PLAY_DIR)/renderer.c \
					$(INITIAL_DIR)/init_event.c \
					$(INITIAL_DIR)/init_input.c \
					$(INITIAL_DIR)/init_libx.c \
					$(INITIAL_DIR)/init_map.c \
					$(INITIAL_DIR)/init_texture.c \
					$(INITIAL_DIR)/init_player.c \
					$(INITIAL_DIR)/init_screen.c \
					$(INITIAL_DIR)/init_map_obj.c \
					$(MINIMAP_DIR)/find_minimap.c \
					$(MINIMAP_DIR)/mini_insert.c \
					$(MINIMAP_DIR)/mini_obj_insert.c \
					$(MINIMAP_DIR)/new_image_minimap.c \
					$(MINIMAP_DIR)/new_image_case.c \
					$(MINIMAP_DIR)/minimap.c \
					$(MINIMAP_DIR)/make_mini_player.c \
					$(UTILITY_DIR)/colors.c\
					$(UTILITY_DIR)/map_vaildity.c \
					$(UTILITY_DIR)/util1.c \
					$(UTILITY_DIR)/util2.c \
					$(UTILITY_DIR)/util3.c \
					$(UTILITY_DIR)/util4.c \
					$(UTILITY_DIR)/test.c \
					$(INPUTDATA_DIR)/input_data.c \
					$(INPUTDATA_DIR)/input_img.c \
					$(INPUTDATA_DIR)/input_player.c \
					$(INPUTDATA_DIR)/input_wall_img.c \
					$(INPUTDATA_DIR)/make_img_box.c \
					$(DRAWWALLIMG_DIR)/draw_img_init.c \
					$(DRAWWALLIMG_DIR)/draw_background.c \
					$(DRAWWALLIMG_DIR)/draw_other_img_calc.c \
					$(DRAWWALLIMG_DIR)/draw_other_img_raycating.c \
					$(DRAWWALLIMG_DIR)/draw_wall_img.c \
					$(DRAWWALLIMG_DIR)/drawing_img.c \
					$(DRAWWALLIMG_DIR)/pixel_inout.c
MAIN_OBJ		=	$(MAIN_SRCS:.c=.o)
OBJS			=	$(subst $(SRCS_DIR), $(OBJS_DIR), $(MAIN_OBJ))
LIBGNL			=	$(LIBS_DIR)/GNL/LIBGNL.a
LIBMLX			=	$(LIBS_DIR)/MLX/libmlx.dylib
#COLOR
Color_Off	=	"\033[0m"
LRed		=	"\033[1;31m"
LGreen		=	"\033[1;32m"
LBlue		=	"\033[1;34m"
LPurple		=	"\033[1;35m"
LCyan		=	"\033[1;36m"
INFO		=

all : $(NAME)

mlx :
	@$(MAKE) -C $(LIBS_DIR)/MLX

$(NAME) : $(OBJS)
	$(eval INFO = $(shell echo $(LBlue)Compiling$(Color_Off)))
	$(info $(INFO))
	@$(MAKE) -C $(LIBS_DIR)/GNL
	$(eval INFO = $(shell echo $(LCyan)libgnl.a "  "✅$(Color_Off)))
	$(info $(INFO))
	@$(MAKE) -C $(LIBS_DIR)/MLX
	$(eval INFO = $(shell echo $(LCyan)mlx.dylib " "✅$(Color_Off)))
	$(info $(INFO))
	@$(CC) $(CFLAGS) -o $@ $^ $(LIBGNL) $(MLXFLAGS) -L$(LIBS_DIR)/MLX -lmlx
	@-install_name_tool -change libmlx.dylib ./$(LIBMLX) $(NAME)
	$(eval INFO = $(shell echo $(LPurple)cub3D "     "✅$(Color_Off)))
	$(info $(INFO))
	$(eval INFO = $(shell echo $(LGreen)Done!$(Color_Off)))
	$(info $(INFO))
	$(info )
	$(eval INFO = $(shell echo $(LBlue)MLX processing...$(Color_Off)))
	$(info $(INFO))

$(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
$(GM_PLAY_OBJ)/%.o : $(GM_PLAY_DIR)/%.c | $(GM_PLAY_OBJ)
	@$(CC) $(CFLAGS) -c $< -o $@
$(INITIAL_OBJ)/%.o : $(INITIAL_DIR)/%.c | $(INITIAL_OBJ)
	@$(CC) $(CFLAGS) -c $< -o $@
$(MINIMAP_OBJ)/%.o : $(MINIMAP_DIR)/%.c | $(MINIMAP_OBJ)
	@$(CC) $(CFLAGS) -c $< -o $@
$(UTILITY_OBJ)/%.o : $(UTILITY_DIR)/%.c | $(UTILITY_OBJ)
	@$(CC) $(CFLAGS) -c $< -o $@
$(INPUTDATA_OBJ)/%.o : $(INPUTDATA_DIR)/%.c | $(INPUTDATA_OBJ)
	@$(CC) $(CFLAGS) -c $< -o $@
$(DRAWWALLIMG_OBJ)/%.o : $(DRAWWALLIMG_DIR)/%.c | $(DRAWWALLIMG_OBJ)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	$(eval INFO = $(shell echo $(LBlue)Create DIR$(Color_Off)))
	$(info $(INFO))
	@mkdir -p $(OBJS_DIR)
	$(eval INFO = $(shell echo $(LCyan)srcs "      "✅$(Color_Off)))
	$(info $(INFO))
	@mkdir -p $(GM_PLAY_OBJ)
	$(eval INFO = $(shell echo $(LCyan)gameplay "  "✅$(Color_Off)))
	$(info $(INFO))
	@mkdir -p $(INITIAL_OBJ)
	$(eval INFO = $(shell echo $(LCyan)initial "   "✅$(Color_Off)))
	$(info $(INFO))
	@mkdir -p $(MINIMAP_OBJ)
	$(eval INFO = $(shell echo $(LCyan)minimap "   "✅$(Color_Off)))
	$(info $(INFO))
	@mkdir -p $(UTILITY_OBJ)
	$(eval INFO = $(shell echo $(LCyan)utility "   "✅$(Color_Off)))
	$(info $(INFO))
	@mkdir -p $(INPUTDATA_OBJ)
	$(eval INFO = $(shell echo $(LCyan)input_data "   "✅$(Color_Off)))
	$(info $(INFO))
	@mkdir -p $(DRAWWALLIMG_OBJ)
	$(eval INFO = $(shell echo $(LCyan)draw_wall_img "   "✅$(Color_Off)))
	$(info $(INFO))
	$(eval INFO = $(shell echo $(LGreen)Done!$(Color_Off)))
	$(info $(INFO))
	$(info )

clean :
	$(eval INFO = $(shell echo $(LRed)Cleaning$(Color_Off)))
	$(info $(INFO))
	@$(MAKE) -C $(LIBS_DIR)/GNL fclean
	$(eval INFO = $(shell echo $(LCyan)libgnl "    "✅$(Color_Off)))
	$(info $(INFO))
	@$(MAKE) -C $(LIBS_DIR)/MLX fclean
	$(eval INFO = $(shell echo $(LCyan)libmlx "    "✅$(Color_Off)))
	$(info $(INFO))
	@$(RM) $(OBJS_DIR)
	$(eval INFO = $(shell echo $(LCyan)ObjDir "    "✅$(Color_Off)))
	$(info $(INFO))
	$(eval INFO = $(shell echo $(LGreen)Done!$(Color_Off)))
	$(info $(INFO))
	$(info )

fclean : clean
	$(eval INFO = $(shell echo $(LRed)Removing$(Color_Off)))
	$(info $(INFO))
	@$(RM) $(NAME)
	$(eval INFO = $(shell echo $(LPurple)cub3D "     "✅$(Color_Off)))
	$(info $(INFO))
	$(eval INFO = $(shell echo $(LGreen)Done!$(Color_Off)))
	$(info $(INFO))
	$(info )

re :
	@$(MAKE) fclean
	@$(MAKE) all


.PHONY : all clean fclean re