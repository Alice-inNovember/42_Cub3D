/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:54:59 by junlee2           #+#    #+#             */
/*   Updated: 2023/05/06 12:33:34 by sounchoi         ###   ########.fr       */
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

static void	make_wall_img(t_image *wall_img, t_libx *mlx);

int	renderer(t_data *data)
{
	make_wall_img(data->texture->wall_img, data->libx);
	draw_wall_img(data->texture->wall_img, data);
	// mlx_sync(MLX_SYNC_IMAGE_WRITABLE, data->texture->wall_img->img);
	mlx_put_image_to_window(data->libx->mlx, data->libx->mlx_win, \
	data->texture->background->img, 0, 0);
	mlx_put_image_to_window(data->libx->mlx, data->libx->mlx_win,\
	data->texture->wall_img->img, 0, 0);
	mlx_put_image_to_window(data->libx->mlx, data->libx->mlx_win, \
	(data->mini->mini_obj[(int)(data->player->pos_x / 10)]\
	[(int)(data->player->pos_y / 10)]).img.img, 0, 0);
	// mlx_sync(MLX_SYNC_WIN_FLUSH_CMD, data->libx->mlx);
	mlx_destroy_image(data->libx->mlx, data->texture->wall_img->img);
	return (0);
}

static void	make_wall_img(t_image *wall_img, t_libx *mlx)
{
	wall_img->img = mlx_new_image(mlx->mlx, G_W, G_H);
	wall_img->addr = \
	mlx_get_data_addr(wall_img->img, &wall_img->bits_per_pixel, \
	&wall_img->line_length, &wall_img->endian);
}
