/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:33:40 by junlee2           #+#    #+#             */
/*   Updated: 2023/05/06 18:49:02 by sounchoi         ###   ########.fr       */
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

static int	mouse_handle(int x, int y, void *parme)
{
	t_data *data;

	data = parme;
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

void	init_event(t_data *data)
{
	make_wall_img(data->texture->wall_img, data->libx);
	mouse_init(&data->mouse);
	mlx_hook(data->libx->mlx_win, ON_DESTROY, 0, &red_button_hook, data); //종료
	mlx_hook(data->libx->mlx_win, 2, 1L<<0, &key_hook, data);
	// mlx_key_hook(data->libx->mlx_win, &key_hook, data);   //캐릭터 이동.
	mlx_hook(data->libx->mlx_win, 6, 0, &mouse_handle, data);
	mlx_loop_hook(data->libx->mlx, &renderer, data);  //여기서 이미지 넣어줌.
}
