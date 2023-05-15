/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_backstep.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:36:26 by junlee2           #+#    #+#             */
/*   Updated: 2023/05/15 12:33:36 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/data.h"
#include <stdio.h>

void	ck_stuck(t_data *data, char **map, float pos_x, float pos_y)
{
	if (map[(int)(pos_x + 0.1)][(int)pos_y] == '1')
		data->player->pos_x += -0.05;
	if (map[(int)(pos_x - 0.1)][(int)pos_y] == '1')
		data->player->pos_x += 0.05;
	if (map[(int)pos_x][(int)(pos_y + 0.1)] == '1')
		data->player->pos_y += -0.05;
	if (map[(int)pos_x][(int)(pos_y - 0.1)] == '1')
		data->player->pos_y += 0.05;
}

void	backstep(t_data *data)
{
	char	**map;
	float	pos_x;
	float	pos_y;

	map = data->map->map;
	pos_x = data->player->pos_x;
	pos_y = data->player->pos_y;
	ck_stuck(data, map, pos_x, pos_y);
	if (map[(int)pos_x][(int)pos_y] == '1')
	{
		if ((int)(pos_x) - (pos_x) > 0)
			data->player->pos_x -= 0.1;
		else
			data->player->pos_x += 0.1;
		if ((int)(pos_y) - (pos_y) > 0)
			data->player->pos_y -= 0.1;
		else
			data->player->pos_y += 0.1;
	}
}
