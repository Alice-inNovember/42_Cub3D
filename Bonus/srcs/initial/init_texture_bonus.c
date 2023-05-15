/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:23:45 by junlee2           #+#    #+#             */
/*   Updated: 2023/05/15 13:10:47 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../libs/MLX/mlx.h"
#include "../../incs/data_bonus.h"

void	init_texture(t_data *data)
{
	data->texture->wall_img = malloc(sizeof(t_image) * 1);
	data->texture->wall_e = malloc(sizeof(t_image) * 1);
	data->texture->wall_n = malloc(sizeof(t_image) * 1);
	data->texture->wall_s = malloc(sizeof(t_image) * 1);
	data->texture->wall_w = malloc(sizeof(t_image) * 1);
	data->texture->door = malloc(sizeof(t_image) * 1);
}
