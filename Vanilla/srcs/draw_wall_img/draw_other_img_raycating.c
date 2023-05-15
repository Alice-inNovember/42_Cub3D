/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_other_img_raycating.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:16:27 by junlee2           #+#    #+#             */
/*   Updated: 2023/05/13 17:06:19 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/draw_game_img.h"

void	select_img(t_player *player, t_detail_info *info)
{
	if (info->side == 1)
	{
		if (info->map_y > player->pos_y)
			info->four_dir = 0;
		else
			info->four_dir = 2;
	}
	else
	{
		if (info->map_x > player->pos_x)
			info->four_dir = 3;
		else
			info->four_dir = 1;
	}
}

void	ray_casting(t_map *map, t_detail_info *info)
{
	while (info->hit == 0)
	{
		if (info->first_dist_x < info->first_dist_y)
		{
			info->first_dist_x += info->squ_per_dist_x;
			info->map_x += info->step_x;
			info->side = 0;
		}
		else
		{
			info->first_dist_y += info->squ_per_dist_y;
			info->map_y += info->step_y;
			info->side = 1;
		}
		if (map->map[info->map_x][info->map_y] == '1')
			info->hit = 1;
		else if (map->map[info->map_x][info->map_y] == 'M')
			info->hit = 2;
	}
}

void	input_need_for_raycating(t_player *player, t_detail_info *info, int x)
{
	info->ray_range = ((2 * x) / (double)G_W) - 1;
	info->ray_dir_x = player->dir_x + (player->plane_x * info->ray_range);
	info->ray_dir_y = player->dir_y + (player->plane_y * info->ray_range);
	info->map_x = (int)player->pos_x;
	info->map_y = (int)player->pos_y;
	info->squ_per_dist_x = fabs(1 / info->ray_dir_x);
	info->squ_per_dist_y = fabs(1 / info->ray_dir_y);
}

void	input_ray_step(t_player *player, t_detail_info *info)
{
	if (info->ray_dir_x < 0)
	{
		info->step_x = -1;
		info->first_dist_x = \
		(player->pos_x - info->map_x) * info->squ_per_dist_x;
	}
	else
	{
		info->step_x = 1;
		info->first_dist_x = \
		(info->map_x + 1.0 - player->pos_x) * info->squ_per_dist_x;
	}
	if (info->ray_dir_y < 0)
	{
		info->step_y = -1;
		info->first_dist_y = \
		(player->pos_y - info->map_y) * info->squ_per_dist_y;
	}
	else
	{
		info->step_y = 1;
		info->first_dist_y = \
		(info->map_y + 1.0 - player->pos_y) * info->squ_per_dist_y;
	}
}
