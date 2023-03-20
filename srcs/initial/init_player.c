/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:01:41 by junlee2           #+#    #+#             */
/*   Updated: 2023/03/20 19:04:07 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/data.h"
#include "../../incs/util.h"

void	init_player(t_data *data)
{
	data->player->pos_x = 3;
	data->player->pos_y = 3;
	data->player->dir_x = -1;
	data->player->dir_y = 0;
	data->player->plane_x = 0;
	data->player->plane_y = 0.66;
}
