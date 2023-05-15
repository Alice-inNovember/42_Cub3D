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
SRCS			=	$(D_SRCS)/main.c \
					$(SD_GM_PLAY)/hook_box.c \
					$(SD_GM_PLAY)/key_player_move.c \
					$(SD_GM_PLAY)/player_backstep.c \
					$(SD_GM_PLAY)/key_player_rotate.c \
					$(SD_GM_PLAY)/mouse_set.c \
					$(SD_GM_PLAY)/renderer.c \
					$(SD_GM_PLAY)/key_door_control.c \
					$(SD_INITIAL)/init_event.c \
					$(SD_INITIAL)/init_input.c \
					$(SD_INITIAL)/init_libx.c \
					$(SD_INITIAL)/init_map.c \
					$(SD_INITIAL)/init_texture.c \
					$(SD_INITIAL)/init_player.c \
					$(SD_INITIAL)/init_screen.c \
					$(SD_INITIAL)/init_map_obj.c \
					$(SD_MINIMAP)/mini_insert.c \
					$(SD_MINIMAP)/mini_obj_insert.c \
					$(SD_MINIMAP)/new_image_minimap.c \
					$(SD_MINIMAP)/new_image_case.c \
					$(SD_MINIMAP)/minimap.c \
					$(SD_MINIMAP)/make_mini_player.c \
					$(SD_UTILITY)/colors.c\
					$(SD_UTILITY)/map_vaildity.c \
					$(SD_UTILITY)/util1.c \
					$(SD_UTILITY)/util2.c \
					$(SD_UTILITY)/util3.c \
					$(SD_UTILITY)/util4.c \
					$(SD_INPUTDATA)/input_data.c \
					$(SD_INPUTDATA)/input_img.c \
					$(SD_INPUTDATA)/input_player.c \
					$(SD_INPUTDATA)/input_wall_img.c \
					$(SD_INPUTDATA)/make_img_box.c \
					$(SD_DRAWWALLIMG)/draw_img_init.c \
					$(SD_DRAWWALLIMG)/draw_background.c \
					$(SD_DRAWWALLIMG)/draw_other_img_calc.c \
					$(SD_DRAWWALLIMG)/draw_other_img_raycating.c \
					$(SD_DRAWWALLIMG)/draw_wall_img.c \
					$(SD_DRAWWALLIMG)/drawing_img.c \
					$(SD_DRAWWALLIMG)/pixel_inout.c
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
	@-install_name_tool -change libmlx.dylib Vanilla/$(LIBMLX) $(NAME)
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