/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_obj.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:23:10 by junlee2           #+#    #+#             */
/*   Updated: 2023/05/12 14:23:12 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/data.h"

void	init_map_obj(t_data *data)
{
	data->map_obj->c = 0;
	data->map_obj->player = 0;
	data->map_obj->player_pos[0] = 0;
	data->map_obj->player_pos[1] = 1;
}
