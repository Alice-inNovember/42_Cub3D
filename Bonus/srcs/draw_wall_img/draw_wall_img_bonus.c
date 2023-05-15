/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_img_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:16:38 by junlee2           #+#    #+#             */
/*   Updated: 2023/05/15 13:09:28 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/draw_game_img_bonus.h"

void	draw_wall_img(t_image *game_img, t_data *data)
{
	int				x;
	t_detail_info	info;
	t_other_draw	draw_info;

	x = 0;
	draw_background(data->texture->wall_img, data->texture);
	while (x < G_W)
	{
		init_info(&info);
		init_draw_init(&draw_info);
		input_need_for_raycating(data->player, &info, x);
		input_ray_step(data->player, &info);
		ray_casting(data->map, &info);
		if (info.hit == 1)
			select_img(data->player, &info);
		else if (info.hit == 2)
			info.four_dir = 4;
		calc_dist_valti(&info);
		draw_pixel_st_en(&draw_info, &info);
		calc_draw_img_others(&draw_info, data->player, &info);
		drawing_game_img(&draw_info, game_img, \
		data->texture->img_box[info.four_dir], x);
		x++;
	}
}
