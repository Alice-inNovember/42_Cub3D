/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_data_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:23:38 by junlee2           #+#    #+#             */
/*   Updated: 2023/05/15 15:51:46 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/input_data_bonus.h"
#include "../../incs/util_bonus.h"

void	input_data(t_data *data)
{
	if (data->map_obj->player == 0)
		err_exit(E_PLAYERCNT);
	input_player(data->map_obj, data->player);
	data->map->map[data->map_obj->player_pos[0]] \
	[data->map_obj->player_pos[1]] = '0';
	input_img(data->input, data->texture, data->libx);
}
