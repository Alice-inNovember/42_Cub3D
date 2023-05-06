/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_controll.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:58:23 by junlee2           #+#    #+#             */
/*   Updated: 2023/05/06 12:38:27 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include "../../incs/data.h"

static void	left_right(t_data *data, int x, int y)
{
	double		speed;
	double		delta_x;
	double		delta_y;

	speed = 1;
	delta_x = data->player->pos_x + x * data->player->plane_x * speed;
	delta_y = data->player->pos_y + y * data->player->plane_y * speed;
	if (data->map->map[(int)(delta_x)][(int)(data->player->pos_y)] == '0')
		data->player->pos_x = delta_x;
	if (data->map->map[(int)(data->player->pos_x)][(int)(delta_y)] == '0')
		data->player->pos_y = delta_y;
}

static void	up_down(t_data *data, int x, int y)
{
	double		speed;
	double		delta_x;
	double		delta_y;

	speed = 1;
	delta_x = data->player->pos_x + x * data->player->dir_x * speed;
	delta_y = data->player->pos_y + y * data->player->dir_y * speed;
	if (data->map->map[(int)(delta_x)][(int)(data->player->pos_y)] == '0')
		data->player->pos_x = delta_x;
	if (data->map->map[(int)(data->player->pos_x)][(int)(delta_y)] == '0')
		data->player->pos_y = delta_y;
}

void	player_move(t_data *data, int flag)
{
	if (flag == 1)
		up_down(data, 1 ,1);
	else if (flag == 2)
		up_down(data, -1, -1);
	else if (flag == 3)
		left_right(data, 1, 1);
	else if (flag == 4)
		left_right(data, -1, -1);
}

void	player_rotate(t_data *data, int speed)
{
	double	old_dir_x;
	double	old_plane_x;
	double	angle;

	angle = 0.1 * speed;
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

int	red_button_hook(t_data *data)
{
	exit(EXIT_SUCCESS);
	(void)data;
	return (0);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		exit(EXIT_SUCCESS);
	else if (keycode == KEY_UP || keycode == 13)
	{
		write(1, "UP\n", 3);
		player_move(data, 1);
	}
	else if (keycode == KEY_DOWN || keycode == 1)
	{
		write(1, "DOWN\n", 6);
		player_move(data, 2);
	}
	else if (keycode == 2)
	{
		write(1, "RIGHT\n", 6);
		player_move(data, 3);
	}
	else if (keycode == 0)
	{
		write(1, "LEFT\n", 5);
		player_move(data, 4);
	}
	if (keycode == KEY_LEFT)
	{
		write(1, "<-\n", 4);
		player_rotate(data, 1);
	}
	if (keycode == KEY_RIGHT)
	{
		write(1, "->\n", 4);
		player_rotate(data, -1);
	}
	return (0);
}