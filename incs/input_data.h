#ifndef INPUT_DATA_H
# define INPUT_DATA_H

#include "data.h"

// input_data.c
void	input_data(t_data *data);
// input_img.c
void	input_img(t_input *input, t_texture *tex, t_libx *mlx);
// input_player.c
void	input_player(t_map_obj *map_obj, t_player *player);
void	input_pos(t_map_obj *map_obj, t_player *player);
void	input_dir_plane(int x, t_player *player);
// input_wall_img.c
void	tran_mlx_img(t_input *input, t_texture *tex, t_libx *mlx);
void	make_t_images(t_texture *tex);
// make_img_box.c
void	make_img_box(t_texture *tex);

#endif