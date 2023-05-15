/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:01:43 by junlee2           #+#    #+#             */
/*   Updated: 2023/03/20 19:48:51 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/data.h"
#include "../../incs/util.h"
#include "../../libs/MLX/mlx.h"

void	init_screen(t_data *data)
{
	data->screen->img = mlx_new_image(data->libx->mlx, 640, 480);
	data->screen->addr = mlx_get_data_addr(\
						data->screen->img, \
						&data->screen->bits_per_pixel, \
						&data->screen->line_length, \
						&data->screen->endian \
						);
}