/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:54:59 by junlee2           #+#    #+#             */
/*   Updated: 2023/05/15 15:56:23 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../libs/MLX/mlx.h"
#include "../../incs/data_bonus.h"
#include "../../incs/util_bonus.h"
#include "../../incs/draw_game_img_bonus.h"
#include "../../incs/player_controll_bonus.h"
#include <unistd.h>

// MLX_SYNC_IMAGE_WRITABLE
// MLX_SYNC_WIN_FLUSH_CMD
// MLX_SYNC_WIN_CMD_COMPLETED

static	int	key_event(t_player_control control)
{
	int	flag;

	flag = control.a + control.d + control.left + \
	control.right + control.s + control.w;
	return (flag);
}

int	renderer(t_data *data)
{
	if (key_event(data->control))
		move_control(data);
	mlx_put_image_to_window(data->libx->mlx, data->libx->mlx_win, \
	data->texture->wall_img->img, 0, 0);
	draw_wall_img(data->texture->wall_img, data);
	mlx_put_image_to_window(data->libx->mlx, data->libx->mlx_win, \
	(data->mini->mini_obj[(int)(data->player->pos_x / 10)] \
	[(int)(data->player->pos_y / 10)]).img.img, 0, 0);
	mlx_put_image_to_window(data->libx->mlx, data->libx->mlx_win, \
	data->mini->player->img, \
	((int)(data->player->pos_y * 10) % 100 - 1) * 15 / 10, \
	((int)(data->player->pos_x * 10) % 100 - 1) * 15 / 10);
	return (0);
}
