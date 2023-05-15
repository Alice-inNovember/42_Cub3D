/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:24:08 by junlee2           #+#    #+#             */
/*   Updated: 2023/05/15 15:13:33 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/input_data.h"

void	input_player(t_map_obj *map_obj, t_player *player)
{
	input_pos(map_obj, player);
	input_dir_plane(map_obj->c, player);
}

void	input_pos(t_map_obj *map_obj, t_player *player)
{
	player->pos_x = (double)(map_obj->player_pos[0]);
	player->pos_y = (double)(map_obj->player_pos[1]);
}

void	input_dir_plane(int x, t_player *player)
{
	if (x == 'N')
	{
		player->dir_x = -1.0;
		player->plane_y = 0.66;
	}
	else if (x == 'S')
	{
		player->dir_x = 1.0;
		player->plane_y = -0.66;
	}
	else if (x == 'W')
	{
		player->dir_y = -1.0;
		player->plane_x = -0.66;
	}
	else if (x == 'E')
	{
		player->dir_y = 1.0;
		player->plane_x = 0.66;
	}
	player->pos_y += 0.5;
	player->pos_x += 0.5;
}
