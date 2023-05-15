/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:23:45 by junlee2           #+#    #+#             */
/*   Updated: 2023/05/13 16:59:14 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libs/MLX/mlx.h"
#include "../../incs/data.h"

void	init_texture(t_data *data)
{
	data->texture->wall_img = malloc(sizeof(t_image) * 1);
	data->texture->wall_e = malloc(sizeof(t_image) * 1);
	data->texture->wall_n = malloc(sizeof(t_image) * 1);
	data->texture->wall_s = malloc(sizeof(t_image) * 1);
	data->texture->wall_w = malloc(sizeof(t_image) * 1);
	data->texture->door = malloc(sizeof(t_image) * 1);
}
