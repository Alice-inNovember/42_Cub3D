/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_img_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:16:50 by junlee2           #+#    #+#             */
/*   Updated: 2023/05/15 13:09:30 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/draw_game_img_bonus.h"

void	drawing_game_img(t_other_draw *draw_info, \
t_image *game_img, t_image img, int x)
{
	int	y;

	y = draw_info->draw_start;
	while (y < draw_info->draw_end)
	{
		draw_info->get_img_y = (int)draw_info->draw_pos & (IMG_H - 1);
		draw_info->color = \
		get_color(&img, draw_info->get_img_x, draw_info->get_img_y);
		my_mlx_pixel_put(game_img, x, y, draw_info->color);
		y++;
		draw_info->draw_pos += draw_info->step;
	}
}
