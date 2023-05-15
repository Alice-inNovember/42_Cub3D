/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_player_move_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:18:34 by junlee2           #+#    #+#             */
/*   Updated: 2023/05/15 13:09:50 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/data_bonus.h"
#include "../../incs/player_controll_bonus.h"

void	move_control(t_data *data)
{
	if (data->control.a == 1)
		key_player_move(KEY_A, data);
	if (data->control.d == 1)
		key_player_move(KEY_D, data);
	if (data->control.w == 1)
		key_player_move(KEY_W, data);
	if (data->control.s == 1)
		key_player_move(KEY_S, data);
	if (data->control.left == 1)
		key_player_rotate(KEY_LEFT, data);
	if (data->control.right == 1)
		key_player_rotate(KEY_RIGHT, data);
}

void	key_player_move(int keycode, t_data *data)
{
	if (keycode == KEY_UP || keycode == KEY_W)
	{
		up_down(data, 1, 1);
	}
	else if (keycode == KEY_DOWN || keycode == KEY_S)
	{
		up_down(data, -1, -1);
	}
	else if (keycode == KEY_D)
	{
		left_right(data, 1, 1);
	}
	else if (keycode == KEY_A)
	{
		left_right(data, -1, -1);
	}
}

void	left_right(t_data *data, int x, int y)
{
	double		speed;
	double		delta_x;
	double		delta_y;
	double		pos_x;
	double		pos_y;

	pos_x = data->player->pos_x;
	pos_y = data->player->pos_y;
	speed = 0.005 * data->control.shift;
	delta_x = pos_x + x * data->player->plane_x * speed;
	delta_y = pos_y + y * data->player->plane_y * speed;
	if (data->map->map[(int)(delta_x)][(int)(pos_y)] == '0' ||
		data->map->map[(int)(delta_x)][(int)(pos_y)] == 'O')
	{
		if (move_detail(data->map->map, delta_x, pos_y, 0) == 1)
			data->player->pos_x = delta_x;
	}
	if (data->map->map[(int)(pos_x)][(int)(delta_y)] == '0' ||
		data->map->map[(int)(pos_x)][(int)(delta_y)] == 'O')
	{
		if (move_detail(data->map->map, pos_x, delta_y, 1) == 1)
			data->player->pos_y = delta_y;
	}
}

void	up_down(t_data *data, int x, int y)
{
	double		speed;
	double		delta_x;
	double		delta_y;
	double		pos_x;
	double		pos_y;

	pos_x = data->player->pos_x;
	pos_y = data->player->pos_y;
	speed = 0.005 * data->control.shift;
	delta_x = pos_x + x * data->player->dir_x * speed;
	delta_y = pos_y + y * data->player->dir_y * speed;
	if (data->map->map[(int)(delta_x)][(int)(pos_y)] == '0' ||
		data->map->map[(int)(delta_x)][(int)(pos_y)] == 'O')
	{
		if (move_detail(data->map->map, delta_x, pos_y, 0) == 1)
			data->player->pos_x = delta_x;
	}
	if (data->map->map[(int)(pos_x)][(int)(delta_y)] == '0' ||
		data->map->map[(int)(pos_x)][(int)(delta_y)] == 'O')
	{
		if (move_detail(data->map->map, pos_x, delta_y, 1) == 1)
			data->player->pos_y = delta_y;
	}
	backstep(data);
}

int	move_detail(char **map, double x, double y, int cas)
{
	if (cas == 1)
	{
		if ((\
		map[(int)(x)][(int)(y + 0.15)] != '1' && \
		map[(int)(x)][(int)(y - 0.15)] != '1') && (\
		map[(int)(x)][(int)(y + 0.15)] != 'M' && \
		map[(int)(x)][(int)(y - 0.15)] != 'M'))
			return (1);
	}
	else
	{
		if ((\
		map[(int)(x + 0.15)][(int)(y)] != '1' && \
		map[(int)(x - 0.15)][(int)(y)] != '1') && (\
		map[(int)(x + 0.15)][(int)(y)] != 'M' && \
		map[(int)(x - 0.15)][(int)(y)] != 'M'))
			return (1);
	}
	return (0);
}
