/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:33:40 by junlee2           #+#    #+#             */
/*   Updated: 2023/04/27 19:28:27 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../../libs/MLX/mlx.h"
#include "../../incs/data.h"
#include "../../incs/renderer.h"
#include "../../incs/player_controll.h"

void	init_event(t_data *data)
{
	make_wall_img(data->texture->wall_img, data->libx);
	draw_wall_img(*data->texture->wall_img, data);
	mlx_put_image_to_window(data->libx->mlx, data->libx->mlx_win, \
	data->texture->background, 0, 0);
	mlx_put_image_to_window(data->libx->mlx, data->libx->mlx_win,\
	data->texture->wall_img, 0, 0);
	mlx_put_image_to_window(data->libx->mlx, data->libx->mlx_win, \
	data->mini->mini_obj[(int)(data->player->pos_y / 10)]\
	[(int)(data->player->pos_x / 10)].img.img, \
	0, 0);
	// mlx_hook(data->libx->mlx_win, ON_DESTROY, 0, red_button_hook, &data); //종료
	// mlx_key_hook(data->libx->mlx_win, key_hook, &data);   //캐릭터 이동.
	mlx_loop_hook(data->libx->mlx_win, renderer, &data);  //여기서 이미지 넣어줌.
}
