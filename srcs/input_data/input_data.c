/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:23:38 by junlee2           #+#    #+#             */
/*   Updated: 2023/05/12 19:56:46 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/input_data.h"
#include "../../incs/util.h"

void	input_data(t_data *data)
{
	if (data->map_obj->player == 0)
		err_exit("zero player..\n");
	input_player(data->map_obj, data->player);
	data->map->map[data->map_obj->player_pos[0]] \
	[data->map_obj->player_pos[1]] = '0';
	input_img(data->input, data->texture, data->libx);
}
