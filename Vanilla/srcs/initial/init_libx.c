/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_libx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:37:23 by junlee2           #+#    #+#             */
/*   Updated: 2023/05/15 15:24:37 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../libs/MLX/mlx.h"
#include "../../incs/data.h"
#include "../../incs/util.h"
#include <stddef.h>

void	init_libx(t_data *data)
{
	t_libx	*libx;

	libx = data->libx;
	libx->mlx = mlx_init();
	libx->win_name = ft_strdup("Cub3D");
}
