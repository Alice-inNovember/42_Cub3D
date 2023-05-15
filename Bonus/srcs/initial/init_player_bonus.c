/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:01:41 by junlee2           #+#    #+#             */
/*   Updated: 2023/05/15 13:10:40 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/data_bonus.h"
#include "../../incs/util_bonus.h"

void	init_player(t_data *data)
{
	data->player->pos_x = 0.0;
	data->player->pos_y = 0.0;
	data->player->dir_x = 0.0;
	data->player->dir_y = 0.0;
	data->player->plane_x = 0.0;
	data->player->plane_y = 0.0;
}
