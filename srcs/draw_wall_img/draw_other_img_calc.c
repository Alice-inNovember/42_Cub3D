/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_other_img_calc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:16:18 by junlee2           #+#    #+#             */
/*   Updated: 2023/05/12 14:16:21 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/draw_game_img.h"

void	calc_draw_img_others(t_other_draw *draw_info, \
t_player *player, t_detail_info *info)
{
	if (info->side == 0)
	{
		draw_info->wall_x = \
		player->pos_y + (info->verti_wall_dist * info->ray_dir_y);
	}
	else
	{
		draw_info->wall_x = \
		player->pos_x + (info->verti_wall_dist * info->ray_dir_x);
	}
	draw_info->wall_x -= floor(draw_info->wall_x);
	draw_info->get_img_x = (int)(draw_info->wall_x * (double)IMG_W);
	if ((info->side == 0 && info->ray_dir_x > 0) || \
	(info->side == 1 && info->ray_dir_y < 0))
		draw_info->get_img_x = IMG_W - draw_info->get_img_x - 1;
	draw_info->step = 1.0 * IMG_H / draw_info->away_dist;
	draw_info->draw_pos = ((draw_info->draw_start - \
	(G_H / 2) + (draw_info->away_dist / 2)) * draw_info->step);
}

void	calc_dist_valti(t_detail_info *info)
{
	if (info->side == 0)
		info->verti_wall_dist = (info->first_dist_x - info->squ_per_dist_x);
	else
		info->verti_wall_dist = (info->first_dist_y - info->squ_per_dist_y);
}

void	draw_pixel_st_en(t_other_draw *draw_info, t_detail_info *info)
{
	draw_info->away_dist = (int)(G_H / info->verti_wall_dist);
	draw_info->draw_start = \
	(-draw_info->away_dist / 2) + (G_H / 2);
	if (draw_info->draw_start < 0)
		draw_info->draw_start = 0;
	draw_info->draw_end = \
	(draw_info->away_dist / 2) + (G_H / 2);
	if (draw_info->draw_end >= G_H)
		draw_info->draw_end = G_H - 1;
}
