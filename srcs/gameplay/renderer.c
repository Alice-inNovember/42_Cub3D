/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:54:59 by junlee2           #+#    #+#             */
/*   Updated: 2023/05/06 17:19:37 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libs/MLX/mlx.h"
#include "../../incs/data.h"
#include "../../incs/util.h"
#include "../../incs/draw_game_img.h"
#include <stdio.h>
#include <unistd.h>

// MLX_SYNC_IMAGE_WRITABLE
// MLX_SYNC_WIN_FLUSH_CMD
// MLX_SYNC_WIN_CMD_COMPLETED

int	renderer(t_data *data)
{
	draw_wall_img(data->texture->wall_img, data);
	mlx_put_image_to_window(data->libx->mlx, data->libx->mlx_win,\
	data->texture->wall_img->img, 0, 0);
	mlx_put_image_to_window(data->libx->mlx, data->libx->mlx_win, \
	(data->mini->mini_obj[(int)(data->player->pos_x / 10)]\
	[(int)(data->player->pos_y / 10)]).img.img, 0, 0);
	mlx_put_image_to_window(data->libx->mlx, data->libx->mlx_win, data->mini->player->img, \
	((int)(data->player->pos_y * 10) % 100 - 1) * 15 / 10, ((int)(data->player->pos_x * 10) % 100 - 1) * 15 / 10);
	return (0);
}
