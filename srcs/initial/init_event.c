/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:33:40 by junlee2           #+#    #+#             */
/*   Updated: 2023/05/13 17:12:25 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../../libs/MLX/mlx.h"
#include "../../incs/data.h"
#include "../../incs/renderer.h"
#include "../../incs/player_controll.h"
#include "../../incs/util.h"
#include "../../incs/draw_game_img.h"

static void	make_wall_img(t_image *wall_img, t_libx *mlx)
{
	wall_img->img = mlx_new_image(mlx->mlx, G_W, G_H);
	wall_img->addr = \
	mlx_get_data_addr(wall_img->img, &wall_img->bits_per_pixel, \
	&wall_img->line_length, &wall_img->endian);
}

static void	mouse_init(t_mouse *mouse)
{
	mouse->mouse_x = 0;
	mouse->mouse_y = 0;
	mouse->tran_mouse = -1;
	mouse->mouse_speed = 1;
}

void	init_event(t_data *data)
{
	make_wall_img(data->texture->wall_img, data->libx);
	data->control.a = 0;
	data->control.s = 0;
	data->control.a = 0;
	data->control.d = 0;
	data->control.right = 0;
	data->control.left = 0;
	data->control.shift = 1;
	mouse_init(&data->mouse);
	mlx_hook(data->libx->mlx_win, ON_DESTROY, 0, &red_button_hook, data);
	mlx_hook(data->libx->mlx_win, 2, 1L << 0, &key_press_hook, data);
	mlx_hook(data->libx->mlx_win, 3, 1L << 1, &key_release_hook, data);
	mlx_hook(data->libx->mlx_win, 6, 0, &mouse_hook, data);
	mlx_loop_hook(data->libx->mlx, &renderer, data);
}
