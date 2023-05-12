#ifndef MINIMAP_H
# define MINIMAP_H

#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "../libs/MLX/mlx.h"

// minimap.c
int		minimap(t_map *map_data, t_data *data);
void	my_mlx_pixel_put(t_image *data, int x, int y, int color);

// mini_insert.c
int		mini_insert(t_map *map_data, t_mini *mini);
void	mini_init(t_mini *mini);
void	mini_insert_xy(t_map *map_data, t_mini *mini);
int		mini_obj_malloc(t_mini *mini);
void	mini_obj_free(t_mini *mini, int max);

// mini_obj_insert.c
int		mini_obj_insert(t_mini *mini, t_map *map_data);
int		mini_obj_init(t_mini *mini);
int		mini_obj_map_malloc(t_mini_obj *mini_obj);
void	mini_obj_map_insert(t_mini_obj **mini_obj, t_map *map_data, t_mini *mini);

// find_imagemap.c
void	find_minimap(t_mini *mini);
void	print_minimap(t_mini_obj mini_obj);

// new_image_minimap.c
int		new_image_minimap(t_mini *mini, t_libx *mlx);
void	init_fp(void (*fp[3])(t_image *, int, int));
int		new_img(char **map, t_image *img, void *mlx, void (*fp[3])(t_image *, int, int));

// new_image_case.c
void	mini_draw_wall(t_image *img, int y, int x);
void	mini_draw_floor(t_image *img, int y, int x);
void	mini_draw_out(t_image *img, int y, int x);
void	mini_draw_door(t_image *img, int y, int x);

// make_mini_player.c
void	make_mini_player(t_mini *mini, t_libx *mlx);

#endif