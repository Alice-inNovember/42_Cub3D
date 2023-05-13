/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game_img.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:28:44 by junlee2           #+#    #+#             */
/*   Updated: 2023/05/14 00:35:48 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_GAME_IMG_H
# define DRAW_GAME_IMG_H

# include "data.h"
# include <math.h>

// draw_background
void			draw_background(t_image *wall_img, t_texture *tex);
void			draw_ceiling(t_image *game_img, t_rgb ceiling);
void			draw_floor(t_image *game_img, t_rgb floor);

// draw_img_init.c
void			init_info(t_detail_info *info);
void			init_draw_init(t_other_draw *draw_info);

// draw_other_img_calc.c
void			calc_draw_img_others(t_other_draw *draw_info, \
				t_player *player, t_detail_info *info);
void			calc_draw_img_one(t_other_draw *draw_info, \
				t_player *player, t_detail_info *info);
void			calc_dist_valti(t_detail_info *info);
void			draw_pixel_st_en(t_other_draw *draw_info, t_detail_info *info);

// draw_other_img_raycating.c
void			select_img(t_player *player, t_detail_info *info);
void			ray_casting(t_map *map, t_detail_info *info);
void			input_need_for_raycating(t_player *player, \
				t_detail_info *info, int x);
void			input_ray_step(t_player *player, t_detail_info *info);

// draw_other_img.c
void			draw_wall_img(t_image *game_img, t_data *data);

//drawing_img.c
// void			draw_ceiling(t_image game_img, t_rgb ceiling);
// void			draw_floor(t_image game_img, t_rgb floor);
void			drawing_game_img(t_other_draw *draw_info, \
				t_image *game_img, t_image img, int x);

// pixel_inout.c
void			my_mlx_pixel_put(t_image *data, int x, int y, int color);
unsigned int	get_color(t_image *data, int x, int y);

#endif
