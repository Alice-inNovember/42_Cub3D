/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_door_control.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:58:23 by junlee2           #+#    #+#             */
/*   Updated: 2023/05/13 23:31:26 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include "../../incs/data.h"
#include "../../incs/player_controll.h"

void	door_open_cloce(t_data *data)
{
	t_player	*player;

	player = data->player;
	printf("%d\n", 123);
	if (fabs(data->player->dir_x) < fabs(data->player->dir_y))
	{
		if (player->dir_y < 0)
			control_door(data->map->map, \
			(int)player->pos_x, (int)player->pos_y - 1);
		else if (player->dir_y > 0)
			control_door(data->map->map, \
			(int)player->pos_x, (int)player->pos_y + 1);
	}
	else
	{
		if (player->dir_x > 0)
			control_door(data->map->map, \
			(int)player->pos_x + 1, (int)player->pos_y);
		else if (player->dir_x < 0)
			control_door(data->map->map, \
			(int)player->pos_x - 1, (int)player->pos_y);
	}
}

void	control_door(char **map, int x, int y)
{
	if (map[x][y] == 'M')
		map[x][y] = 'O';
	else if (map[x][y] == 'O')
		map[x][y] = 'M';
}
