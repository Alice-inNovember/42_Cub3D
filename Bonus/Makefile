#NAME------------------------------------------------------
NAME				=	../cub3D
#CMDS------------------------------------------------------
CC					=	cc
RM					=	rm -rf
LIBC				=	ar rcs
#FLAGS-----------------------------------------------------
CFLAGS				=	-Wall -Wextra -Werror
MLXFLAGS			=	-framework OpenGL -framework AppKit
#DIRS------------------------------------------------------
D_LIBS			=	libs
D_INCS			=	incs
D_SRCS			=	srcs
D_OBJS			=	objs

SD_GM_PLAY		=	$(D_SRCS)/gameplay
SD_INITIAL		=	$(D_SRCS)/initial
SD_MINIMAP		=	$(D_SRCS)/minimap
SD_UTILITY		=	$(D_SRCS)/utility
SD_INPUTDATA	=	$(D_SRCS)/input_data
SD_DRAWWALLIMG	=	$(D_SRCS)/draw_wall_img


OD_GM_PLAY		=	$(D_OBJS)/gameplay
OD_INITIAL		=	$(D_OBJS)/initial
OD_MINIMAP		=	$(D_OBJS)/minimap
OD_UTILITY		=	$(D_OBJS)/utility
OD_INPUTDATA	=	$(D_OBJS)/input_data
OD_DRAWWALLIMG	=	$(D_OBJS)/draw_wall_img
#FILES-----------------------------------------------------
SRCS			=	$(D_SRCS)/main_bonus.c \
					$(SD_GM_PLAY)/hook_box_bonus.c \
					$(SD_GM_PLAY)/key_player_move_bonus.c \
					$(SD_GM_PLAY)/player_backstep_bonus.c \
					$(SD_GM_PLAY)/key_player_rotate_bonus.c \
					$(SD_GM_PLAY)/mouse_set_bonus.c \
					$(SD_GM_PLAY)/renderer_bonus.c \
					$(SD_GM_PLAY)/key_door_control_bonus.c \
					$(SD_INITIAL)/init_event_bonus.c \
					$(SD_INITIAL)/init_input_bonus.c \
					$(SD_INITIAL)/init_libx_bonus.c \
					$(SD_INITIAL)/init_map_bonus.c \
					$(SD_INITIAL)/init_texture_bonus.c \
					$(SD_INITIAL)/init_player_bonus.c \
					$(SD_INITIAL)/init_screen_bonus.c \
					$(SD_INITIAL)/init_map_obj_bonus.c \
					$(SD_MINIMAP)/mini_insert_bonus.c \
					$(SD_MINIMAP)/mini_obj_insert_bonus.c \
					$(SD_MINIMAP)/new_image_minimap_bonus.c \
					$(SD_MINIMAP)/new_image_case_bonus.c \
					$(SD_MINIMAP)/minimap_bonus.c \
					$(SD_MINIMAP)/make_mini_player_bonus.c \
					$(SD_UTILITY)/colors_bonus.c \
					$(SD_UTILITY)/map_vaildity_bonus.c \
					$(SD_UTILITY)/util1_bonus.c \
					$(SD_UTILITY)/util2_bonus.c \
					$(SD_UTILITY)/util3_bonus.c \
					$(SD_UTILITY)/util4_bonus.c \
					$(SD_INPUTDATA)/input_data_bonus.c \
					$(SD_INPUTDATA)/input_img_bonus.c \
					$(SD_INPUTDATA)/input_player_bonus.c \
					$(SD_INPUTDATA)/input_wall_img_bonus.c \
					$(SD_INPUTDATA)/make_img_box_bonus.c \
					$(SD_DRAWWALLIMG)/draw_img_init_bonus.c \
					$(SD_DRAWWALLIMG)/draw_background_bonus.c \
					$(SD_DRAWWALLIMG)/draw_other_img_calc_bonus.c \
					$(SD_DRAWWALLIMG)/draw_other_img_raycating_bonus.c \
					$(SD_DRAWWALLIMG)/draw_wall_img_bonus.c \
					$(SD_DRAWWALLIMG)/drawing_img_bonus.c \
					$(SD_DRAWWALLIMG)/pixel_inout_bonus.c
OBJS			=	$(subst $(D_SRCS), $(D_OBJS), $(SRCS:.c=.o))
LIBGNL			=	$(D_LIBS)/GNL/LIBGNL.a
LIBMLX			=	$(D_LIBS)/MLX/libmlx.dylib
#COLOR-----------------------------------------------------
C_OFF			=	"\033[0m"
C_RED			=	"\033[1;31m"
C_GRN			=	"\033[1;32m"
C_BLE			=	"\033[1;34m"
C_PLE			=	"\033[1;35m"
C_CYN			=	"\033[1;36m"
INFO			=
#PRINTER---------------------------------------------------
define P_STAT
	$(eval INFO = $(shell echo $(1)$(C_OFF)))
	$(info $(INFO))
endef
#KEY-------------------------------------------------------
all : $(NAME)
#NAME------------------------------------------------------
$(NAME) : $(OBJS)
	$(call P_STAT,$(C_BLE)Compiling)

	@$(MAKE) -C $(D_LIBS)/GNL --silent
	$(call P_STAT,$(C_CYN)libgnl.a"     "✅)
	@$(MAKE) -C $(D_LIBS)/MLX --silent
	$(call P_STAT,$(C_CYN)mlx.dylib"    "✅)

	@$(CC) $(CFLAGS) -o $@ $^ $(LIBGNL) $(MLXFLAGS) -L$(D_LIBS)/MLX -lmlx
	@-install_name_tool -change libmlx.dylib Bonus/$(LIBMLX) $(NAME)
	$(call P_STAT,$(C_PLE)cub3D"        "✅)

	$(call P_STAT,$(C_GRN)Done!)
	$(info )
	$(call P_STAT,$(C_BLE)MLX processing...)
#OBJS------------------------------------------------------
$(D_OBJS)/%.o : $(D_SRCS)/%.c | $(D_OBJS)
	@$(CC) $(CFLAGS) -c $< -o $@ 
$(OD_GM_PLAY)/%.o : $(SD_GM_PLAY)/%.c | $(OD_GM_PLAY)
	@$(CC) $(CFLAGS) -c $< -o $@
$(OD_INITIAL)/%.o : $(SD_INITIAL)/%.c | $(OD_INITIAL)
	@$(CC) $(CFLAGS) -c $< -o $@
$(OD_MINIMAP)/%.o : $(SD_MINIMAP)/%.c | $(OD_MINIMAP)
	@$(CC) $(CFLAGS) -c $< -o $@
$(OD_UTILITY)/%.o : $(SD_UTILITY)/%.c | $(OD_UTILITY)
	@$(CC) $(CFLAGS) -c $< -o $@
$(OD_INPUTDATA)/%.o : $(SD_INPUTDATA)/%.c | $(OD_INPUTDATA)
	@$(CC) $(CFLAGS) -c $< -o $@
$(OD_DRAWWALLIMG)/%.o : $(SD_DRAWWALLIMG)/%.c | $(OD_DRAWWALLIMG)
	@$(CC) $(CFLAGS) -c $< -o $@
#MKDIR-----------------------------------------------------
$(D_OBJS):
	$(call P_STAT,$(C_BLE)Create DIR)

	@mkdir -p $(D_OBJS)
	$(call P_STAT,$(C_CYN)D_OBJS"       "✅)

	@mkdir -p $(OD_GM_PLAY)
	$(call P_STAT,$(C_CYN)OD_GM_PLAY"   "✅)

	@mkdir -p $(OD_INITIAL)
	$(call P_STAT,$(C_CYN)OD_INITIAL"   "✅)

	@mkdir -p $(OD_MINIMAP)
	$(call P_STAT,$(C_CYN)OD_MINIMAP"   "✅)

	@mkdir -p $(OD_UTILITY)
	$(call P_STAT,$(C_CYN)OD_UTILITY"   "✅)

	@mkdir -p $(OD_INPUTDATA)
	$(call P_STAT,$(C_CYN)OD_IN_DATA"   "✅)

	@mkdir -p $(OD_DRAWWALLIMG)
	$(call P_STAT,$(C_CYN)OD_WALLIMG"   "✅)

	$(call P_STAT,$(C_GRN)Done!)
	$(info )
#CLEAN-----------------------------------------------------
clean :
	$(call P_STAT,$(C_RED)Cleaning)
	
	@$(MAKE) -C $(D_LIBS)/GNL fclean --silent
	$(call P_STAT,$(C_CYN)libgnl"       "✅)

	@$(MAKE) -C $(D_LIBS)/MLX fclean --silent
	$(call P_STAT,$(C_CYN)libmlx"       "✅)

	@$(RM) $(D_OBJS)
	$(call P_STAT,$(C_CYN)ObjDir"       "✅)

	$(call P_STAT,$(C_GRN)Done!)
	$(info )
#FCLEAN----------------------------------------------------
fclean : clean
	$(call P_STAT,$(C_RED)Removing)

	@$(RM) $(NAME)
	$(call P_STAT,$(C_PLE)cub3D"        "✅)

	$(call P_STAT,$(C_GRN)Done!)
	$(info )
#RE--------------------------------------------------------
re :
	@$(MAKE) fclean --silent
	@$(MAKE) all --silent

.PHONY : all clean fclean re