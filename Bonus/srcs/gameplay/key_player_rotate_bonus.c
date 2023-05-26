/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_player_rotate_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:19:32 by junlee2           #+#    #+#             */
/*   Updated: 2023/05/26 16:17:19 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/data_bonus.h"
#include "../../incs/player_controll_bonus.h"
#include <math.h>

void	key_player_rotate(int keycode, t_data *data)
{
	if (keycode == KEY_LEFT)
	{
		player_rotate(data, 30);
	}
	if (keycode == KEY_RIGHT)
	{
		player_rotate(data, -30);
	}
}

void	player_rotate(t_data *data, int speed)
{
	double	old_dir_x;
	double	old_plane_x;
	double	angle;

	angle = 0.001 * speed;
	old_dir_x = data->player->dir_x;
	old_plane_x = data->player->plane_x;
	data->player->dir_x = data->player->dir_x * cos(angle) - \
	data->player->dir_y * sin(angle);
	data->player->dir_y = old_dir_x * sin(angle) + \
	data->player->dir_y * cos(angle);
	data->player->plane_x = data->player->plane_x * cos(angle) - \
	data->player->plane_y * sin(angle);
	data->player->plane_y = old_plane_x * sin(angle) + \
	data->player->plane_y * cos(angle);
}
