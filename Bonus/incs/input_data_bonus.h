/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_data_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:28:44 by junlee2           #+#    #+#             */
/*   Updated: 2023/05/15 13:08:42 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_DATA_BONUS_H
# define INPUT_DATA_BONUS_H

# include "data_bonus.h"

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