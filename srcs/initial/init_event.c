/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:33:40 by junlee2           #+#    #+#             */
/*   Updated: 2023/05/01 18:51:51 by sounchoi         ###   ########.fr       */
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

static void	make_wall_img(t_image *wall_img, t_libx *mlx);

void	init_event(t_data *data)
{
	make_wall_img(data->texture->wall_img, data->libx);
	draw_wall_img(data->texture->wall_img, data);
	mlx_put_image_to_window(data->libx->mlx, data->libx->mlx_win, \
	data->texture->background->img, 0, 0);
	mlx_put_image_to_window(data->libx->mlx, data->libx->mlx_win,\
	data->texture->wall_img->img, 0, 0);
	mlx_put_image_to_window(data->libx->mlx, data->libx->mlx_win, \
	(data->mini->mini_obj[(int)(data->player->pos_x / 10)]\
	[(int)(data->player->pos_y / 10)]).img.img, \
	0, 0);
	mlx_loop(data->libx->mlx);
	// mlx_hook(data->libx->mlx_win, ON_DESTROY, 0, red_button_hook, &data); //종료
	// mlx_key_hook(data->libx->mlx_win, key_hook, &data);   //캐릭터 이동.
	mlx_loop_hook(data->libx->mlx_win, renderer, &data);  //여기서 이미지 넣어줌.
}

static void	make_wall_img(t_image *wall_img, t_libx *mlx)
{
	wall_img->img = mlx_new_image(mlx->mlx, G_W, G_H);
	wall_img->addr = \
	mlx_get_data_addr(wall_img->img, &wall_img->bits_per_pixel, \
	&wall_img->line_length, &wall_img->endian);
}
