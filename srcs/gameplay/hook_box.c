/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_box.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:58:23 by junlee2           #+#    #+#             */
/*   Updated: 2023/05/07 20:27:44 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include "../../incs/data.h"
#include "../../incs/player_controll.h"

int	red_button_hook(t_data *data)
{
	exit(EXIT_SUCCESS);
	(void)data;
	return (0);
}

// int	key_hook(int keycode, t_data *data)
// {
// 	if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
// 		key_player_rotate(keycode, data);
// 	else if (keycode == MOUSE_SET || \
// 	keycode == MOUSE_SPD_UP || keycode == MOUSE_SPD_DOWN)
// 		mouse_set(keycode, data);
// 	else
// 		key_player_move(keycode, data);
// 	return (0);
// }

int	key_press_hook(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		exit(EXIT_SUCCESS);
	else if (keycode == MOUSE_SET || \
	keycode == MOUSE_SPD_UP || keycode == MOUSE_SPD_DOWN)
		mouse_set(keycode, data);
	else if (keycode == KEY_W || keycode == KEY_UP)
		data->control.w = 1;
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		data->control.s = 1;
	else if (keycode == KEY_A)
		data->control.a = 1;
	else if (keycode == KEY_D)
		data->control.d = 1;
	else if (keycode == KEY_RIGHT)
		data->control.right = 1;
	else if (keycode == KEY_LEFT)
		data->control.left = 1;
	else if (keycode == KEY_SHIFT)
		data->control.shift = 5;
	return (0);
}

int key_release_hook(int keycode, t_data *data)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		data->control.w = 0;
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		data->control.s = 0;
	else if (keycode == KEY_A)
		data->control.a = 0;
	else if (keycode == KEY_D)
		data->control.d = 0;
	else if (keycode == KEY_RIGHT)
		data->control.right = 0;
	else if (keycode == KEY_LEFT)
		data->control.left = 0;
		else if (keycode == KEY_SHIFT)
		data->control.shift = 1;
	return (0);
}

int	mouse_hook(int x, int y, t_data *data)
{
	data->mouse.mouse_x = x;
	data->mouse.mouse_y = y;
	if (data->mouse.tran_mouse == 1)
	{
		if (x < G_W / 2)
			player_rotate(data, data->mouse.mouse_speed);
		else if (x > G_H / 2)
			player_rotate(data, -data->mouse.mouse_speed);
		mlx_mouse_move(data->libx->mlx_win, G_W / 2, G_H / 2);
	}
	return (0);
}
