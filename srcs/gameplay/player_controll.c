/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_controll.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:58:23 by junlee2           #+#    #+#             */
/*   Updated: 2023/03/20 17:52:07 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include "../../incs/data.h"

void	player_move(t_data *data, int speed)
{
	t_player	*player;
	t_map		*map;
	double		delta_x;
	double		delta_y;

	player = data->player;
	map = data->map;
	delta_x = player->pos_x + player->dir_x * speed;
	delta_y = player->pos_y + player->dir_y * speed;
	if (map->map[(int)(delta_x)][(int)(player->pos_y)] == '0')
		player->pos_x = delta_x;
	if (map->map[(int)(player->pos_x)][(int)(delta_y)] == '0')
		player->pos_y = delta_y;
}

void	player_rotate(t_data *data, int speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->player->dir_x;
	old_plane_x = data->player->plane_x;
	data->player->dir_x = data->player->dir_x * cos(speed) - \
	data->player->dir_y * sin(speed);
	data->player->dir_y = old_dir_x * sin(speed) + \
	data->player->dir_y * cos(speed);
	data->player->plane_x = data->player->plane_x * cos(speed) - \
	data->player->plane_y * sin(speed);
	data->player->plane_y = old_plane_x * sin(speed) + \
	data->player->plane_y * cos(speed);
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
	if (keycode == KEY_DOWN)
		write(1, "DOWN\n", 5);
	if (keycode == KEY_UP)
		write(1, "UP\n", 3);
	if (keycode == KEY_RIGHT)
		write(1, "RIGHT\n", 6);
	if (keycode == KEY_LEFT)
		write(1, "LEFT\n", 5);
	(void)data;
	return (0);
}