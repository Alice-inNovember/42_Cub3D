/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:23:45 by junlee2           #+#    #+#             */
/*   Updated: 2023/05/15 15:34:53 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../libs/MLX/mlx.h"
#include "../../incs/data.h"
#include "../../incs/util.h"

void	init_texture(t_data *data)
{
	data->texture->wall_img = ft_malloc(sizeof(t_image) * 1);
	data->texture->wall_e = ft_malloc(sizeof(t_image) * 1);
	data->texture->wall_n = ft_malloc(sizeof(t_image) * 1);
	data->texture->wall_s = ft_malloc(sizeof(t_image) * 1);
	data->texture->wall_w = ft_malloc(sizeof(t_image) * 1);
	data->texture->door = ft_malloc(sizeof(t_image) * 1);
}
