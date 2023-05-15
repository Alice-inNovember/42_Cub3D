/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_img_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:16:06 by junlee2           #+#    #+#             */
/*   Updated: 2023/05/12 14:16:10 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/draw_game_img.h"

void	init_info(t_detail_info *info)
{
	info->first_dist_x = 0.0;
	info->first_dist_y = 0.0;
	info->hit = 0;
	info->map_x = 0;
	info->map_y = 0;
	info->ray_dir_x = 0.0;
	info->ray_dir_y = 0.0;
	info->ray_range = 0.0;
	info->squ_per_dist_x = 0.0;
	info->squ_per_dist_y = 0.0;
	info->step_x = 0;
	info->step_y = 0;
	info->verti_wall_dist = 0.0;
	info->four_dir = 0;
	info->side = 0;
}

void	init_draw_init(t_other_draw *draw_info)
{
	draw_info->color = 0;
	draw_info->draw_end = 0;
	draw_info->draw_start = 0;
	draw_info->draw_img_x = 0;
	draw_info->draw_img_y = 0;
	draw_info->get_img_x = 0;
	draw_info->get_img_y = 0;
	draw_info->draw_pos = 0.0;
	draw_info->step = 0.0;
	draw_info->away_dist = 0;
	draw_info->wall_x = 0.0;
}
